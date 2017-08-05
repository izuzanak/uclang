
@begin
include "ucl_ga.h"
@end

// - external error identifiers -
unsigned c_ext_error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE = c_idx_not_exist;

/*
 * methods of structure lua_s
 */

float ga_s::objective_real(GAGenome& genome)
{/*{{{*/

  // - retrieve genome pointer -
  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)genome.userData();

  // - return zero if exceprion was thrown -
  if (grg_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return 0.0f;
  }

  interpreter_thread_s &it = *grg_ptr->it_ptr;
  delegate_s *delegate_ptr = (delegate_s *)grg_ptr->objective_dlg->v_data_ptr;

  // - create genome location -
  GARealGenome *genome_ptr = (GARealGenome *)&genome;
  BIC_CREATE_NEW_LOCATION_REFS(genome_location,c_bi_class_ga_tmp_real_genome,genome_ptr,0);

  // - callback parameters -
  const unsigned param_cnt = 1;
  pointer param_data = genome_location;

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,&param_data,param_cnt,trg_location,grg_ptr->source_pos,
      grg_ptr->ret_code = c_run_return_code_EXCEPTION;

      return 0.0f;
      );

  double ret_value;

  // - ERROR -
  if (!it.retrieve_float(trg_location,ret_value))
  {
    it.release_location_ptr(trg_location);

    exception_s::throw_exception(it,c_ext_error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE,grg_ptr->source_pos,(location_s *)it.blank_location);
    grg_ptr->ret_code = c_run_return_code_EXCEPTION;

    return 0.0f;
  }

  it.release_location_ptr(trg_location);

  return ret_value;
}/*}}}*/

