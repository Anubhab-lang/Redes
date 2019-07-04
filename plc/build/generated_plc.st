PROGRAM program0
  VAR
    saida AT %QX100.0 : BOOL;
    setpoint AT %QW4 : UINT;
    Temperatura AT %IW100 : UINT;
    SaidaAnalog AT %QW100 : UINT;
    Erro AT %QW20 : INT;
    saida2 AT %QX101.0 : BOOL;
    setpoint2 AT %QW8 : UINT;
    Temperatura2 AT %IW102 : UINT;
    SaidaAnalog2 AT %QW101 : UINT;
    Erro2 AT %QW30 : INT;
    aux1 AT %MW200 : UINT;
    aux2 AT %MX202.0 : BOOL;
    aux3 AT %MW204 : UINT;
    aux4 AT %MX202.1 : BOOL;
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
