void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





static inline INT __PROGRAM0_MOVE__INT__INT1(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE30_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE30_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROGRAM0_MOVE__INT__INT2(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE60_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE60_ENO,,__TMP_ENO);
  return __res;
}

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->SAIDA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SETPOINT,0,retain)
  __INIT_VAR(data__->TEMPERATURA,0,retain)
  __INIT_VAR(data__->SAIDAANALOG,0,retain)
  __INIT_VAR(data__->ERRO,0,retain)
  __INIT_VAR(data__->SAIDA2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SETPOINT2,0,retain)
  __INIT_VAR(data__->TEMPERATURA2,0,retain)
  __INIT_VAR(data__->SAIDAANALOG2,0,retain)
  __INIT_VAR(data__->ERRO2,0,retain)
  __INIT_VAR(data__->AUX1,0,retain)
  __INIT_VAR(data__->AUX2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUX3,0,retain)
  __INIT_VAR(data__->AUX4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_INT26_OUT,0,retain)
  __INIT_VAR(data__->UINT_TO_INT27_OUT,0,retain)
  __INIT_VAR(data__->SUB20_OUT,0,retain)
  __INIT_VAR(data__->UINT_TO_INT52_OUT,0,retain)
  __INIT_VAR(data__->UINT_TO_INT53_OUT,0,retain)
  __INIT_VAR(data__->SUB55_OUT,0,retain)
  __INIT_VAR(data__->LT28_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE30_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE30_OUT,0,retain)
  __INIT_VAR(data__->LT58_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE60_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE60_OUT,0,retain)
  __INIT_VAR(data__->INT_TO_UINT33_OUT,0,retain)
  __INIT_VAR(data__->MUL25_OUT,0,retain)
  __INIT_VAR(data__->INT_TO_UINT65_OUT,0,retain)
  __INIT_VAR(data__->MUL66_OUT,0,retain)
  __INIT_VAR(data__->GT14_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT71_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,UINT_TO_INT26_OUT,,UINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SETPOINT,)));
  __SET_VAR(data__->,UINT_TO_INT27_OUT,,UINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->TEMPERATURA,)));
  __SET_VAR(data__->,SUB20_OUT,,SUB__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->UINT_TO_INT26_OUT,),
    (INT)__GET_VAR(data__->UINT_TO_INT27_OUT,)));
  __SET_VAR(data__->,ERRO,,__GET_VAR(data__->SUB20_OUT,));
  __SET_VAR(data__->,UINT_TO_INT52_OUT,,UINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SETPOINT2,)));
  __SET_VAR(data__->,UINT_TO_INT53_OUT,,UINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->TEMPERATURA2,)));
  __SET_VAR(data__->,SUB55_OUT,,SUB__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->UINT_TO_INT52_OUT,),
    (INT)__GET_VAR(data__->UINT_TO_INT53_OUT,)));
  __SET_VAR(data__->,ERRO2,,__GET_VAR(data__->SUB55_OUT,));
  __SET_VAR(data__->,LT28_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->ERRO,),
    (INT)0));
  __SET_VAR(data__->,MOVE30_OUT,,__PROGRAM0_MOVE__INT__INT1(
    (BOOL)__GET_VAR(data__->LT28_OUT,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->MOVE30_ENO,)) {
    __SET_VAR(data__->,ERRO,,__GET_VAR(data__->MOVE30_OUT,));
  };
  __SET_VAR(data__->,LT58_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->ERRO2,),
    (INT)0));
  __SET_VAR(data__->,MOVE60_OUT,,__PROGRAM0_MOVE__INT__INT2(
    (BOOL)__GET_VAR(data__->LT58_OUT,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->MOVE60_ENO,)) {
    __SET_VAR(data__->,ERRO2,,__GET_VAR(data__->MOVE60_OUT,));
  };
  __SET_VAR(data__->,INT_TO_UINT33_OUT,,INT_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->ERRO,)));
  __SET_VAR(data__->,MUL25_OUT,,MUL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)2,
    (UINT)__GET_VAR(data__->INT_TO_UINT33_OUT,)));
  __SET_VAR(data__->,AUX1,,__GET_VAR(data__->MUL25_OUT,));
  __SET_VAR(data__->,INT_TO_UINT65_OUT,,INT_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->ERRO2,)));
  __SET_VAR(data__->,MUL66_OUT,,MUL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)2,
    (UINT)__GET_VAR(data__->INT_TO_UINT65_OUT,)));
  __SET_VAR(data__->,AUX3,,__GET_VAR(data__->MUL66_OUT,));
  __SET_VAR(data__->,GT14_OUT,,GT__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->TEMPERATURA,),
    (UINT)__GET_VAR(data__->SETPOINT,)));
  __SET_VAR(data__->,AUX2,,__GET_VAR(data__->GT14_OUT,));
  __SET_VAR(data__->,GT71_OUT,,GT__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->TEMPERATURA2,),
    (UINT)__GET_VAR(data__->SETPOINT2,)));
  __SET_VAR(data__->,AUX4,,__GET_VAR(data__->GT71_OUT,));
  __SET_VAR(data__->,SAIDAANALOG2,,__GET_VAR(data__->AUX3,));
  __SET_VAR(data__->,SAIDAANALOG,,__GET_VAR(data__->AUX1,));
  __SET_VAR(data__->,SAIDA2,,__GET_VAR(data__->AUX4,));
  __SET_VAR(data__->,SAIDA,,__GET_VAR(data__->AUX2,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





