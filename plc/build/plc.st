TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR
    saida : BOOL;
    setpoint : UINT;
    Temperatura : UINT;
    SaidaAnalog : UINT;
    Erro : INT;
    saida2 : BOOL;
    setpoint2 : UINT;
    Temperatura2 : UINT;
    SaidaAnalog2 : UINT;
    Erro2 : INT;
    aux1 : UINT;
    aux2 : BOOL;
    aux3 : UINT;
    aux4 : BOOL;
  END_VAR
  VAR
    UINT_TO_INT26_OUT : INT;
    UINT_TO_INT27_OUT : INT;
    SUB20_OUT : INT;
    UINT_TO_INT52_OUT : INT;
    UINT_TO_INT53_OUT : INT;
    SUB55_OUT : INT;
    LT28_OUT : BOOL;
    MOVE30_ENO : BOOL;
    MOVE30_OUT : INT;
    LT58_OUT : BOOL;
    MOVE60_ENO : BOOL;
    MOVE60_OUT : INT;
    INT_TO_UINT33_OUT : UINT;
    MUL25_OUT : UINT;
    INT_TO_UINT65_OUT : UINT;
    MUL66_OUT : UINT;
    GT14_OUT : BOOL;
    GT71_OUT : BOOL;
  END_VAR

  UINT_TO_INT26_OUT := UINT_TO_INT(setpoint);
  UINT_TO_INT27_OUT := UINT_TO_INT(Temperatura);
  SUB20_OUT := SUB(UINT_TO_INT26_OUT, UINT_TO_INT27_OUT);
  Erro := SUB20_OUT;
  UINT_TO_INT52_OUT := UINT_TO_INT(setpoint2);
  UINT_TO_INT53_OUT := UINT_TO_INT(Temperatura2);
  SUB55_OUT := SUB(UINT_TO_INT52_OUT, UINT_TO_INT53_OUT);
  Erro2 := SUB55_OUT;
  LT28_OUT := LT(Erro, 0);
  MOVE30_OUT := MOVE(EN := LT28_OUT, IN := 0, ENO => MOVE30_ENO);
  IF MOVE30_ENO THEN
      Erro := MOVE30_OUT;
  END_IF;
  LT58_OUT := LT(Erro2, 0);
  MOVE60_OUT := MOVE(EN := LT58_OUT, IN := 0, ENO => MOVE60_ENO);
  IF MOVE60_ENO THEN
      Erro2 := MOVE60_OUT;
  END_IF;
  INT_TO_UINT33_OUT := INT_TO_UINT(Erro);
  MUL25_OUT := MUL(2, INT_TO_UINT33_OUT);
  aux1 := MUL25_OUT;
  INT_TO_UINT65_OUT := INT_TO_UINT(Erro2);
  MUL66_OUT := MUL(2, INT_TO_UINT65_OUT);
  aux3 := MUL66_OUT;
  GT14_OUT := GT(Temperatura, setpoint);
  aux2 := GT14_OUT;
  GT71_OUT := GT(Temperatura2, setpoint2);
  aux4 := GT71_OUT;
  SaidaAnalog2 := aux3;
  SaidaAnalog := aux1;
  saida2 := aux4;
  saida := aux2;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
