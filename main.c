#include<stdio.h>

void main()
{
	// declaration of variables
	int deptId, sDayTimeHrs, sNightTimeHrs, wTimeHrs;
	int ePlanId = 0;
	float sDayTimeRate=0, sNightTimeRate=0, wTimeRate=0;
	float summerNightBillCost;
	float deptAnnualElecBill, minAnnualBill,minBill=99999999999;
	float totalEBill=0, maxSumNightTimeBill=0;
	int minDept = 0,deptSumCounter=0;

	//initial prompt which is used to run for loop
	printf("Please enter the Department Id and -1 to exit: ");
	scanf("%d", &deptId);
	//while Loop
	while (deptId != -1)
	{
		//data promps
		printf("\nPlease enter the Summer day time units: ");
		scanf("%d", &sDayTimeHrs);
		printf("Please enter the Summer night time units: ");
		scanf("%d", &sNightTimeHrs);
		printf("Please enter the winter time units: ");
		scanf("%d", &wTimeHrs);
		printf("Please enter the electricity plan Id: ");
		scanf("%d", &ePlanId);
		if (sNightTimeHrs < 1000)
		{
			deptSumCounter++;
		}
		//Departments annual bill calculation
		if (ePlanId == 1)
		{
			sDayTimeRate = 0.5;
			sNightTimeRate = 0.1;
			wTimeRate = 0.6;
		}//if
		else if (ePlanId == 2)
		{
			sDayTimeRate = 0.75;
			sNightTimeRate = 0.2;
			wTimeRate = 0.85;
		}//else if
		else if (ePlanId == 3)
		{
			sDayTimeRate = 1.1;
			sNightTimeRate = 0.3;
			wTimeRate = 1.3;
		}//else if
		else
		{
			printf("Invalid electricity plan Id entered\n");
			break;
		}//else
		summerNightBillCost = sNightTimeHrs*sNightTimeRate;
		deptAnnualElecBill = ((sDayTimeHrs*sDayTimeRate) + summerNightBillCost + (wTimeHrs*wTimeRate));
		// dept with min annual bill calculation
		minAnnualBill = deptAnnualElecBill;
		if (deptAnnualElecBill < minBill)
		{
			minDept = deptId;
			minBill = deptAnnualElecBill;
			
		}
		//totals company bill calculation
		totalEBill = totalEBill + deptAnnualElecBill;
		//max night time bill calc
		if (summerNightBillCost > maxSumNightTimeBill)
		{
			maxSumNightTimeBill = summerNightBillCost;
		}
		//Departments annual bill output
		printf("The total bill of dept %d is %f and the total night time summer cost is %f ", deptId,deptAnnualElecBill, summerNightBillCost);
		//subsequent prompt 
		printf("\nPlease enter the Department Id and -1 to exit: ");
		scanf("%d", &deptId);
	}//while loop
	printf("The total company bill is %f\n", totalEBill);
	printf("The max summer night time bill by any department was %f\n", maxSumNightTimeBill);
	printf("The dept with the min annual bill is %d\n", minDept);
	printf("The number of department with less than 1000 summertime night is %d\n", deptSumCounter);
}//main
