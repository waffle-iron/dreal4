#include "dreal/solver/config.h"

#include <fmt/format.h>

namespace dreal {

using std::ostream;

double Config::precision() const { return precision_.get(); }
OptionValue<double>& Config::mutable_precision() { return precision_; }

bool Config::produce_models() const { return produce_models_.get(); }
OptionValue<bool>& Config::mutable_produce_models() { return produce_models_; }

bool Config::use_polytope() const { return use_polytope_.get(); }
OptionValue<bool>& Config::mutable_use_polytope() { return use_polytope_; }

bool Config::use_polytope_in_forall() const {
  return use_polytope_in_forall_.get();
}
OptionValue<bool>& Config::mutable_use_polytope_in_forall() {
  return use_polytope_in_forall_;
}

bool Config::use_worklist_fixpoint() const {
  return use_worklist_fixpoint_.get();
}
OptionValue<bool>& Config::mutable_use_worklist_fixpoint() {
  return use_worklist_fixpoint_;
}

bool Config::use_local_optimization() const {
  return use_local_optimization_.get();
}
OptionValue<bool>& Config::mutable_use_local_optimization() {
  return use_local_optimization_;
}

double Config::nlopt_ftol_rel() const { return nlopt_ftol_rel_.get(); }

OptionValue<double>& Config::mutable_nlopt_ftol_rel() {
  return nlopt_ftol_rel_;
}

double Config::nlopt_ftol_abs() const { return nlopt_ftol_abs_.get(); }

OptionValue<double>& Config::mutable_nlopt_ftol_abs() {
  return nlopt_ftol_abs_;
}

int Config::nlopt_maxeval() const { return nlopt_maxeval_.get(); }

OptionValue<int>& Config::mutable_nlopt_maxeval() { return nlopt_maxeval_; }

double Config::nlopt_maxtime() const { return nlopt_maxtime_.get(); }

OptionValue<double>& Config::mutable_nlopt_maxtime() { return nlopt_maxtime_; }

ostream& operator<<(ostream& os, const Config& config) {
  return os << fmt::format(
             "Config("
             "precision = {}, "
             "produce_model = {}, "
             "use_polytope = {}, "
             "use_polytope_in_forall = {}, "
             "use_worklist_fixpoint = {}, "
             "use_local_optimization = {}, "
             "nlopt_ftol_rel = {}, "
             "nlopt_ftol_abs = {}, "
             "nlopt_maxeval = {}, "
             "nlopt_maxtime = {}"
             ")",
             config.precision(), config.produce_models(), config.use_polytope(),
             config.use_polytope_in_forall(), config.use_worklist_fixpoint(),
             config.use_local_optimization(), config.nlopt_ftol_rel(),
             config.nlopt_ftol_abs(), config.nlopt_maxeval(),
             config.nlopt_maxtime());
}

}  // namespace dreal
