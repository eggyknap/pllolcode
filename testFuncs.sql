-- Functions for testing PL/LOLCODE
-- $Id: testFuncs.sql,v 1.10 2009/11/03 22:07:23 eggyknap Exp $

DROP FUNCTION pl_lolcode_call_handler() CASCADE;
CREATE FUNCTION pl_lolcode_call_handler() RETURNS LANGUAGE_HANDLER AS 'pllolcode' LANGUAGE C;
CREATE FUNCTION pl_lolcode_validator(oid) RETURNS VOID AS 'pllolcode' LANGUAGE C;
-- If using PostgreSQL 8.5 or above...
CREATE FUNCTION pl_lolcode_inline_handler(internal) RETURNS VOID AS 'pllolcode' LANGUAGE C;
CREATE LANGUAGE pllolcode handler pl_lolcode_call_handler INLINE pl_lolcode_inline_handler VALIDATOR pl_lolcode_validator ;
-- else, if using PostgreSQL 8.4 or below...
-- CREATE LANGUAGE pllolcode handler pl_lolcode_call_handler VALIDATOR pl_lolcode_validator ;
-- end if

CREATE FUNCTION lol_main_test(a text) RETURNS BOOLEAN AS $$
HAI
	VISIBLE NOTICE "This is a test"
	FOUND YR WIN
KTHXBYE
$$
LANGUAGE PLLOLCODE;

CREATE FUNCTION lol_arith_test("ANINT" INT, "ANUDDERINT" INT) RETURNS BOOLEAN AS $$
HAI
	VISIBLE NOTICE "1 This is a test"
	VISIBLE INFO "2 This is a test"
	VISIBLE INFO "First argument"
	VISIBLE INFO ANINT
	VISIBLE INFO "Second argument"
	VISIBLE INFO ANUDDERINT
	VISIBLE INFO "Their sum"
	VISIBLE INFO SUM OF ANINT AN ANUDDERINT
	VISIBLE INFO "Their difference"
	VISIBLE INFO DIFF OF ANINT ANUDDERINT
	VISIBLE INFO "Their product"
	VISIBLE INFO PRODUKT OF ANINT ANUDDERINT
    VISIBLE INFO "Their quotient"
    VISIBLE INFO QUOSHUNT OF ANINT AN ANUDDERINT
	VISIBLE INFO "Their modulus"
	VISIBLE INFO MOD OF ANINT ANUDDERINT
	VISIBLE INFO "Their maximum"
	VISIBLE INFO BIGGR OF ANINT AN ANUDDERINT
	VISIBLE INFO "Their minimum"
	VISIBLE INFO SMALLR OF ANINT ANUDDERINT
	FOUND YR WIN
KTHXBYE
$$ LANGUAGE PLLOLCODE;

CREATE FUNCTION lol_bool_test("ABOOL" BOOL, "MIBOOL" BOOL) RETURNS BOOLEAN AS $$
HAI
	VISIBLE NOTICE "FIRST ARGUMENT"
	VISIBLE NOTICE ABOOL
	VISIBLE NOTICE "SECOND ARGUMENT"
	VISIBLE NOTICE MIBOOL
	VISIBLE NOTICE " NOT 1 "
	VISIBLE NOTICE NOT ABOOL
	VISIBLE NOTICE " 1 AND 2 "
	VISIBLE NOTICE BOTH OF ABOOL AN MIBOOL
	VISIBLE NOTICE " 1 OR 2 "
	VISIBLE NOTICE EITHER OF ABOOL AN MIBOOL
	VISIBLE NOTICE " NOT 1 OR 2 "
	VISIBLE NOTICE NOT EITHER OF ABOOL MIBOOL
	VISIBLE NOTICE " ANY OF 1 2 WIN FAIL MKAY "
	VISIBLE NOTICE ANY OF ABOOL MIBOOL WIN FAIL MKAY
	VISIBLE NOTICE " ALL OF 1 AN 2 AN WIN AN FAIL MKAY "
	VISIBLE NOTICE ALL OF ABOOL AN MIBOOL AN WIN AN FAIL MKAY
	VISIBLE NOTICE " ARE ABOOL AND MIBOOL THE SAME? "
	VISIBLE NOTICE BOTH SAEM ABOOL AN MIBOOL
	VISIBLE NOTICE " ARE ABOOL AND MIBOOL DIFFERENT? "
	VISIBLE NOTICE DIFFRINT ABOOL MIBOOL
	VISIBLE NOTICE " RETURNING 1 XOR 2 "
	FOUND YR WON OF ABOOL MIBOOL
KTHXBYE
$$ LANGUAGE PLLOLCODE;

CREATE FUNCTION lol_misc_bool() RETURNS BOOLEAN AS $$
HAI
	VISIBLE " ALL OF WIN WIN WIN "
	VISIBLE ALL OF WIN WIN WIN MKAY
	VISIBLE " ALL OF WIN WIN FAIL "
	VISIBLE ALL OF WIN WIN FAIL MKAY
	VISIBLE " ANY OF FAIL FAIL FAIL MKAY"
	VISIBLE ANY OF FAIL FAIL FAIL MKAY
	VISIBLE " ANY OF WIN FAIL FAIL MKAY"
	VISIBLE ANY OF WIN FAIL FAIL MKAY
	VISIBLE " WON OF FAIL WIN, WIN WIN, FAIL FAIL "
	VISIBLE WON OF FAIL WIN
	VISIBLE WON OF WIN WIN
	VISIBLE WON OF FAIL FAIL
KTHXBYE
$$ LANGUAGE PLLOLCODE;

-- Function to get libpllolcode loaded, so gdb can see it
CREATE FUNCTION lol_load_library() RETURNS INTEGER AS $$
HAI
	VISIBLE 1
KTHXBYE
$$ LANGUAGE PLLOLCODE;

CREATE FUNCTION lol_find_pi_gregory_leibniz("ITERASHUNZ" INTEGER) RETURNS NUMERIC AS $$
HAI
    BTW Calculate pi using Gregory-Leibniz series
    BTW This method does not converge particularly quickly...
    I HAS A PIADD ITZ 0.0
    I HAS A PISUB ITZ 0.0
    I HAS A ITR ITZ 0
    I HAS A T1
    I HAS A T2
    I HAS A PI ITZ 0.0

    IM IN YR LOOP
        T1 R QUOSHUNT OF 4.0 AN SUM OF 3.0 AN ITR
        T2 R QUOSHUNT OF 4.0 AN SUM OF 5.0 AN ITR
        PISUB R SUM OF PISUB AN T1
        PIADD R SUM OF PIADD AN T2
        ITR R SUM OF ITR AN 4.0
        BOTH SAEM ITR AN BIGGR OF ITR AN ITERASHUNZ, O RLY?
            YA RLY, GTFO
        OIC
    IM OUTTA YR LOOP
    PI R SUM OF 4.0 AN DIFF OF PIADD AN PISUB
    VISIBLE "PI R: "
    VISIBLE PI
    FOUND YR PI
KTHXBYE
$$ LANGUAGE PLLOLCODE;

CREATE FUNCTION lol_spi_test() RETURNS TIMESTAMPTZ AS $$
HAI
    I HAS A TIEM
    GIMMEH TIEM OUTTA DATABUKKIT "SELECT NOW()"
    FOUND YR TIEM 
KTHXBYE
$$ LANGUAGE PLLOLCODE;

CREATE FUNCTION lol_type_args_test("ANUMBR" INTEGER, "ANUMBAR" NUMERIC, "AYARN" TEXT) RETURNS VOID AS $$
HAI
	GIMMEH YR VARZ
KTHXBYE
$$ LANGUAGE PLLOLCODE;

CREATE FUNCTION lol_return_string() RETURNS TEXT AS $$
HAI
	FOUND YR "OMIGOSHIWON!!1"
KTHXBYE
$$ LANGUAGE PLLOLCODE;

select 'lol_load_library';
select lol_load_library();
select 'lol_main_test';
select lol_main_test('This is a test input parameter');
select 'lol_arith_test';
select lol_arith_test(5, 2);
select 'lol_bool_test 1';
select lol_bool_test(true, true);
select 'lol_bool_test 2';
select lol_bool_test(true, false);
select 'lol_bool_test 3';
select lol_bool_test(false, true);
select 'lol_bool_test 4';
select lol_bool_test(false, false);
select 'lol_misc_bool';
select lol_misc_bool();
select 'lol_type_args_test';
select lol_type_args_test(1, 1.2, 'test');
select 'lol_return_string';
select lol_return_string();
select 'lol_find_pi_gregory_leibniz';
select lol_find_pi_gregory_leibniz(100000);
select 'lol_spi_test';
select lol_spi_test();

-- If using PostgreSQL 8.5 or above...
DO $$
HAI
  VISIBLE "This is a test of INLINE stuff"
KTHXBYE
$$ language pllolcode;
-- end if
