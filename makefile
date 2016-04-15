Payroll.out: Payroll.cpp
	g++ Payroll.cpp -o Payroll.out

run: Payroll.out
	./Payroll.out
