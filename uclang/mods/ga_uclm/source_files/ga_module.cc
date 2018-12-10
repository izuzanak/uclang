
@begin
include "ga_module.h"
@end

// - GA indexes of built in classes -
unsigned c_bi_class_ga_real_genome = c_idx_not_exist;
unsigned c_bi_class_ga_tmp_real_genome = c_idx_not_exist;
unsigned c_bi_class_ga_steady_state = c_idx_not_exist;

// - GA module -
built_in_module_s module =
{/*{{{*/
  3,                   // Class count
  ga_classes,          // Classes

  0,                   // Error base index
  8,                   // Error count
  ga_error_strings,    // Error strings

  ga_initialize,       // Initialize function
  ga_print_exception,  // Print exceptions function
};/*}}}*/

// - GA classes -
built_in_class_s *ga_classes[] =
{/*{{{*/
  &ga_real_genome_class,
  &ga_tmp_real_genome_class,
  &ga_steady_state_class,
};/*}}}*/

// - GA error strings -
const char *ga_error_strings[] =
{/*{{{*/
  "error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE",
  "error_GA_GENOME_NEGATIVE_LENGTH",
  "error_GA_GENOME_INVALID_ALLELE_RANGE",
  "error_GA_GENOME_WRONG_OBJECTIVE_DELEGATE",
  "error_GA_GENERATION_COUNT_ZERO_OR_NEGATIVE",
  "error_GA_POPULATION_SIZE_ZERO_OR_NEGATIVE",
  "error_GA_MUTATION_PROBABILITY_RANGE_ERROR",
  "error_GA_CROSSOVER_PROBABILITY_RANGE_ERROR",
};/*}}}*/

// - GA initialize -
bool ga_initialize(script_parser_s &sp)
{/*{{{*/

  // - initialize external error identifiers -
  c_ext_error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE =
    module.error_base + c_error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE;

  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ga_real_genome class identifier -
  c_bi_class_ga_real_genome = class_base_idx++;

  // - initialize ga_tmp_real_genome class identifier -
  c_bi_class_ga_tmp_real_genome = class_base_idx++;

  // - initialize ga_steady_state class identifier -
  c_bi_class_ga_steady_state = class_base_idx++;

  return true;
}/*}}}*/

// - GA print exception -
bool ga_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA genome, objective method does not return float\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GA_GENOME_NEGATIVE_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA genome, requested negative genome length\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GA_GENOME_INVALID_ALLELE_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA genome, requested invalid allele range\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GA_GENOME_WRONG_OBJECTIVE_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA genome, wrong parameter count of objective delegate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GA_GENERATION_COUNT_ZERO_OR_NEGATIVE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA, zero or negative count of generations\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GA_POPULATION_SIZE_ZERO_OR_NEGATIVE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA, zero or negative population size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GA_MUTATION_PROBABILITY_RANGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA, mutation probability out of range\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GA_CROSSOVER_PROBABILITY_RANGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGA, crossover probability out of range\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GA_REAL_GENOME -
built_in_class_s ga_real_genome_class =
{/*{{{*/
  "GaRealGenome",
  c_modifier_public | c_modifier_final,
  8, ga_real_genome_methods,
  0, ga_real_genome_variables,
  bic_ga_real_genome_consts,
  bic_ga_real_genome_init,
  bic_ga_real_genome_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s ga_real_genome_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ga_real_genome_operator_binary_equal
  },
  {
    "GaRealGenome#4",
    c_modifier_public | c_modifier_final,
    bic_ga_real_genome_method_GaRealGenome_4
  },
  {
    "evolve#4",
    c_modifier_public | c_modifier_final,
    bic_ga_real_genome_method_evolve_4
  },
  {
    "steady_state#4",
    c_modifier_public | c_modifier_final,
    bic_ga_real_genome_method_steady_state_4
  },
  {
    "values#0",
    c_modifier_public | c_modifier_final,
    bic_ga_real_genome_method_values_0
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_ga_real_genome_method_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ga_real_genome_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ga_real_genome_method_print_0
  },
};/*}}}*/

built_in_variable_s ga_real_genome_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_GA_REAL_GENOME_RETRIEVE_VALUES() \
{/*{{{*/\
\
  /* - create result array - */\
  pointer_array_s *array_ptr = it.get_new_array_ptr();\
  BIC_CREATE_NEW_LOCATION(array_loc,c_bi_class_array,array_ptr);\
\
  /* - retrieve genome size - */\
  unsigned genome_size = genome_ptr->length();\
\
  /* - retrieve genome genes - */\
  if (genome_size > 0)\
  {\
    unsigned idx = 0;\
    do {\
\
      /* - retrieve gene value - */\
      double value = genome_ptr->gene(idx);\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
      array_ptr->push(new_location);\
\
    } while(++idx < genome_size);\
  }\
\
  BIC_SET_RESULT(array_loc);\
}/*}}}*/

#define BIC_GA_REAL_GENOME_RETRIEVE_DATA() \
{/*{{{*/\
\
  /* - retrieve genome size - */\
  unsigned genome_size = genome_ptr->length();\
\
  /* - create result string - */\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->create(genome_size*sizeof(float));\
\
  /* - retrieve genome genes - */\
  if (genome_size > 0)\
  {\
    unsigned idx = 0;\
    float *s_ptr = (float *)string_ptr->data;\
    do {\
\
      /* - retrieve gene value - */\
      *s_ptr++ = genome_ptr->gene(idx);\
\
    } while(++idx < genome_size);\
  }\
\
  BIC_SET_RESULT_STRING(string_ptr);\
}/*}}}*/

void bic_ga_real_genome_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ga_real_genome_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ga_real_genome_s *)nullptr;
}/*}}}*/

void bic_ga_real_genome_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)location_ptr->v_data_ptr;

  if (grg_ptr != nullptr)
  {
    grg_ptr->clear(it);
    cfree(grg_ptr);
  }
}/*}}}*/

bool bic_ga_real_genome_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ga_real_genome_method_GaRealGenome_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
length:retrieve_integer
lower:retrieve_float
upper:retrieve_float
delegate:c_bi_class_delegate
>
method GaRealGenome
; @end

  // - ERROR -
  if (length <= 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_GENOME_NEGATIVE_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (lower > upper)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_GENOME_INVALID_ALLELE_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  delegate_s *delegate_ptr = (delegate_s *)src_3_location->v_data_ptr;
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_GENOME_WRONG_OBJECTIVE_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create ga real genome object -
  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)cmalloc(sizeof(ga_real_genome_s));
  grg_ptr->init();

  GARealAlleleSet alleles(lower,upper);
  grg_ptr->genome_ptr = new GARealGenome(length,alleles,ga_s::objective_real);

  // - set genome user data pointer -
  grg_ptr->genome_ptr->userData(grg_ptr);

  src_3_location->v_reference_cnt.atomic_inc();
  grg_ptr->objective_dlg = src_3_location;

  dst_location->v_data_ptr = (ga_real_genome_s *)grg_ptr;

  return true;
}/*}}}*/

bool bic_ga_real_genome_method_evolve_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
generation_cnt:retrieve_integer
population_size:retrieve_integer
mutation:retrieve_float
crossover:retrieve_float
>
method evolve
; @end

  // - ERROR -
  if (generation_cnt <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_GENERATION_COUNT_ZERO_OR_NEGATIVE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (population_size <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_POPULATION_SIZE_ZERO_OR_NEGATIVE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (mutation < 0.0 || mutation > 1.0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_MUTATION_PROBABILITY_RANGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (crossover < 0.0 || crossover > 1.0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_CROSSOVER_PROBABILITY_RANGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)dst_location->v_data_ptr;
  grg_ptr->it_ptr = &it;
  grg_ptr->source_pos = operands[c_source_pos_idx];
  grg_ptr->ret_code = c_run_return_code_OK;

  GARealGenome &genome = *grg_ptr->genome_ptr;

  // - create genetic algorithm -
  GASteadyStateGA ga(genome);

  // - set genetic algorithm properties -
  ga.minimize();
  ga.nGenerations(generation_cnt);
  ga.populationSize(population_size);
  ga.pMutation(mutation);
  ga.pCrossover(crossover);

  ga.initialize();
  while(!ga.done() && grg_ptr->ret_code == c_run_return_code_OK)
  {
    ga.step();
  }

  // - if exception occurred -
  if (grg_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  // - retrieve best individual -
  genome = ga.statistics().bestIndividual();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ga_real_genome_method_steady_state_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
generation_cnt:retrieve_integer
population_size:retrieve_integer
mutation:retrieve_float
crossover:retrieve_float
>
method steady_state
; @end

  // - ERROR -
  if (generation_cnt <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_GENERATION_COUNT_ZERO_OR_NEGATIVE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (population_size <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_POPULATION_SIZE_ZERO_OR_NEGATIVE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (mutation < 0.0 || mutation > 1.0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_MUTATION_PROBABILITY_RANGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (crossover < 0.0 || crossover > 1.0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GA_CROSSOVER_PROBABILITY_RANGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)dst_location->v_data_ptr;
  grg_ptr->it_ptr = &it;
  grg_ptr->source_pos = operands[c_source_pos_idx];
  grg_ptr->ret_code = c_run_return_code_OK;

  // - create ga steady state object -
  ga_steady_state_s *gss_ptr = (ga_steady_state_s *)cmalloc(sizeof(ga_steady_state_s));
  gss_ptr->init();

  // - set reference to genome location -
  dst_location->v_reference_cnt.atomic_inc();
  gss_ptr->ga_genome_loc = dst_location;

  // - create steady state genetic algorithm -
  GASteadyStateGA *ga_ptr = new GASteadyStateGA(*grg_ptr->genome_ptr);
  gss_ptr->ga_ptr = ga_ptr;

  ga_ptr->minimize();
  ga_ptr->nGenerations(generation_cnt);
  ga_ptr->populationSize(population_size);
  ga_ptr->pMutation(mutation);
  ga_ptr->pCrossover(crossover);

  ga_ptr->initialize();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ga_steady_state,gss_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ga_real_genome_method_values_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)dst_location->v_data_ptr;

  // - retrieve genome -
  GARealGenome *genome_ptr = grg_ptr->genome_ptr;

  BIC_GA_REAL_GENOME_RETRIEVE_VALUES();

  return true;
}/*}}}*/

bool bic_ga_real_genome_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)dst_location->v_data_ptr;

  // - retrieve genome -
  GARealGenome *genome_ptr = grg_ptr->genome_ptr;

  BIC_GA_REAL_GENOME_RETRIEVE_DATA();

  return true;
}/*}}}*/

bool bic_ga_real_genome_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GaRealGenome"),"GaRealGenome");
  );

  return true;
}/*}}}*/

bool bic_ga_real_genome_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GaRealGenome");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GA_TMP_REAL_GENOME -
built_in_class_s ga_tmp_real_genome_class =
{/*{{{*/
  "GaTmpRealGenome",
  c_modifier_public | c_modifier_final,
  6, ga_tmp_real_genome_methods,
  0, ga_tmp_real_genome_variables,
  bic_ga_tmp_real_genome_consts,
  bic_ga_tmp_real_genome_init,
  bic_ga_tmp_real_genome_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s ga_tmp_real_genome_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ga_tmp_real_genome_operator_binary_equal
  },
  {
    "values#0",
    c_modifier_public | c_modifier_final,
    bic_ga_tmp_real_genome_method_values_0
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_ga_tmp_real_genome_method_data_0
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_ga_tmp_real_genome_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ga_tmp_real_genome_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ga_tmp_real_genome_method_print_0
  },
};/*}}}*/

built_in_variable_s ga_tmp_real_genome_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ga_tmp_real_genome_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ga_tmp_real_genome_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (GARealGenome *)nullptr;
}/*}}}*/

void bic_ga_tmp_real_genome_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_ga_tmp_real_genome_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ga_tmp_real_genome_method_values_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  GARealGenome *genome_ptr = (GARealGenome *)dst_location->v_data_ptr;

  BIC_GA_REAL_GENOME_RETRIEVE_VALUES();

  return true;
}/*}}}*/

bool bic_ga_tmp_real_genome_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  GARealGenome *genome_ptr = (GARealGenome *)dst_location->v_data_ptr;

  BIC_GA_REAL_GENOME_RETRIEVE_DATA();

  return true;
}/*}}}*/

bool bic_ga_tmp_real_genome_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  // - retrieve genome size -
  long long int result = ((GARealGenome *)dst_location->v_data_ptr)->length();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ga_tmp_real_genome_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GaTmpRealGenome"),"GaTmpRealGenome");
  );

  return true;
}/*}}}*/

bool bic_ga_tmp_real_genome_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GaTmpRealGenome");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GA_STEADY_STATE -
built_in_class_s ga_steady_state_class =
{/*{{{*/
  "GaSteadyState",
  c_modifier_public | c_modifier_final,
  6, ga_steady_state_methods,
  0, ga_steady_state_variables,
  bic_ga_steady_state_consts,
  bic_ga_steady_state_init,
  bic_ga_steady_state_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s ga_steady_state_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ga_steady_state_operator_binary_equal
  },
  {
    "done#0",
    c_modifier_public | c_modifier_final,
    bic_ga_steady_state_method_done_0
  },
  {
    "step#0",
    c_modifier_public | c_modifier_final,
    bic_ga_steady_state_method_step_0
  },
  {
    "best_individual#0",
    c_modifier_public | c_modifier_final,
    bic_ga_steady_state_method_best_individual_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ga_steady_state_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ga_steady_state_method_print_0
  },
};/*}}}*/

built_in_variable_s ga_steady_state_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ga_steady_state_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ga_steady_state_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ga_steady_state_s *)nullptr;
}/*}}}*/

void bic_ga_steady_state_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ga_steady_state_s *gss_ptr = (ga_steady_state_s *)location_ptr->v_data_ptr;

  if (gss_ptr != nullptr)
  {
    gss_ptr->clear(it);
    cfree(gss_ptr);
  }
}/*}}}*/

bool bic_ga_steady_state_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ga_steady_state_method_done_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  ga_steady_state_s *gss_ptr = (ga_steady_state_s *)dst_location->v_data_ptr;

  long long int result = gss_ptr->ga_ptr->done();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ga_steady_state_method_step_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ga_steady_state_s *gss_ptr = (ga_steady_state_s *)dst_location->v_data_ptr;

  // - if genetic algoritm is not complete -
  if (!gss_ptr->ga_ptr->done())
  {
    // - retrieve and setup genome pointer -
    ga_real_genome_s *grg_ptr = (ga_real_genome_s *)gss_ptr->ga_genome_loc->v_data_ptr;
    grg_ptr->it_ptr = &it;
    grg_ptr->source_pos = operands[c_source_pos_idx];
    grg_ptr->ret_code = c_run_return_code_OK;

    // - execute one genetic algorithm step -
    gss_ptr->ga_ptr->step();

    // - if exception occurred -
    if (grg_ptr->ret_code == c_run_return_code_EXCEPTION)
    {
      return false;
    }
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ga_steady_state_method_best_individual_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  ga_steady_state_s *gss_ptr = (ga_steady_state_s *)dst_location->v_data_ptr;
  ga_real_genome_s *grg_ptr = (ga_real_genome_s *)gss_ptr->ga_genome_loc->v_data_ptr;

  // - retrieve best individual -
  *grg_ptr->genome_ptr = gss_ptr->ga_ptr->statistics().bestIndividual();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ga_steady_state_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GasteadyState"),"GasteadyState");
  );

  return true;
}/*}}}*/

bool bic_ga_steady_state_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GasteadyState");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

