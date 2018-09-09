#!/bin/bash

testcasefile='testcase1.txt'
testcase='TEST 1'
expected=2
testresult=`./birthday.exe <$testcasefile`
if [ $testresult -eq $expected ]; then
	echo "$testcase: OK"
else 
	echo "$testcase: FAIL- Expected: $expected  Actual: $testresult"
fi


testcasefile='testcase2.txt'
testcase='TEST 2'
expected=0
testresult=`./birthday.exe <$testcasefile`
if [ $testresult -eq $expected ]; then
	echo "$testcase: OK"
else 
	echo "$testcase: FAIL- Expected: $expected  Actual: $testresult"
fi


testcasefile='testcase3.txt'
testcase='TEST 3'
expected=2
testresult=`./birthday.exe <$testcasefile`
if [ $testresult -eq $expected ]; then
	echo "$testcase: OK"
else 
	echo "$testcase: FAIL- Expected: $expected  Actual: $testresult"
fi
