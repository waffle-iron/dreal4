#include "dreal/contractor/contractor_status.h"

#include <utility>

#include "dreal/util/assert.h"

using std::move;
using std::unordered_set;
using std::vector;

namespace dreal {

ContractorStatus::ContractorStatus(Box box, const int branching_point)
    : box_{move(box)},
      branching_point_{branching_point},
      output_{ibex::BitSet::empty(box_.size())} {
  DREAL_ASSERT(!box_.empty());
  DREAL_ASSERT(branching_point_ >= -1 && branching_point_ < box_.size());
}

const Box& ContractorStatus::box() const { return box_; }

Box& ContractorStatus::mutable_box() { return box_; }

int ContractorStatus::branching_point() const { return branching_point_; }

int& ContractorStatus::mutable_branching_point() { return branching_point_; }

const ibex::BitSet& ContractorStatus::output() const { return output_; }

ibex::BitSet& ContractorStatus::mutable_output() { return output_; }

void ContractorStatus::AddUsedConstraint(const Formula& f) {
  if (box_.empty()) {
    for (const Variable& v : f.GetFreeVariables()) {
      AddUnsatWitness(v);
    }
  }
  used_constraints_.insert(f);
}

void ContractorStatus::AddUsedConstraint(const vector<Formula>& formulas) {
  for (const Formula& f : formulas) {
    AddUsedConstraint(f);
  }
}

void ContractorStatus::AddUnsatWitness(const Variable& var) {
  unsat_witness_.insert(var);
}

unordered_set<Formula, hash_value<Formula>> GenerateExplanation(
    const Variables& unsat_witness,
    const unordered_set<Formula, hash_value<Formula>>& used_constraints) {
  // Set up the initial explanation based on variables.
  unordered_set<Formula, hash_value<Formula>> explanation;
  for (const Formula& f_i : used_constraints) {
    if (HaveIntersection(unsat_witness, f_i.GetFreeVariables())) {
      explanation.insert(f_i);
    }
  }

  bool keep_going = true;
  while (keep_going) {
    keep_going = false;
    for (const Formula& f_i : explanation) {
      const Variables variables_in_f_i{f_i.GetFreeVariables()};
      for (const Formula& f_j : used_constraints) {
        if (explanation.count(f_j) > 0) {
          continue;
        }
        if (HaveIntersection(variables_in_f_i, f_j.GetFreeVariables())) {
          explanation.insert(f_j);
          keep_going = true;
        }
      }
    }
  }
  return explanation;
}

unordered_set<Formula, hash_value<Formula>> ContractorStatus::Explanation()
    const {
  DREAL_ASSERT(!unsat_witness_.empty());
  return GenerateExplanation(unsat_witness_, used_constraints_);
}

ContractorStatus& ContractorStatus::InplaceJoin(
    const ContractorStatus& contractor_status) {
  box_.InplaceUnion(contractor_status.box());
  output_ |= contractor_status.output();
  unsat_witness_.insert(contractor_status.unsat_witness_.begin(),
                        contractor_status.unsat_witness_.end());
  used_constraints_.insert(contractor_status.used_constraints_.begin(),
                           contractor_status.used_constraints_.end());
  return *this;
}

ContractorStatus Join(ContractorStatus contractor_status1,
                      const ContractorStatus& contractor_status2) {
  // This function updates `contractor_status1`, which is passed by value, and
  // returns it.
  return contractor_status1.InplaceJoin(contractor_status2);
}

}  // namespace dreal
