#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

/*an instance of this struct holds the weather data for a single day*/
struct DailyData{
    int day;
    int month;
    int year;
    float high;
    float low;
    float precipitation;
    char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic{
    float minTemperature;
    float maxTemperature;
    float averageTemperature;
    float totalPrecipitation;
};
int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],
                    int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );

int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    if(!fp){
        printf("you need to put historicaldata.csv into this directory\n");
        exit(0);
    }
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;

    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    int i;
    struct MonthlyStatistic monthly[12];
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);
    sortYearData(yearData,numDays);

    for(i=0;i<12;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);
    }

    printf("Weather summary for %d\n",year);
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    for(i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);
    }
    printf("\n\n");
    printf("Precipitation Graph\n\n");
    for (i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);
    }
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:\n");
        printVerbose(yearData,numDays);
    }
    return 0;
}
int readDailyData(FILE* fp, struct DailyData allData[]){
    int i=0;
    while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n",
        &allData[i].year,&allData[i].month,&allData[i].day,
        &allData[i].high,&allData[i].low,&allData[i].precipitation,
        &allData[i].condition) == 7){
        i++;
    }
    return i;
}
int getRelevantRecords(int yearWanted, const struct DailyData allData[], 
                                    int sz,  struct DailyData yearData[]){

//    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);

//put your code here

int i = 0;
int x = 0;
int count = 0;

	for (i = 0; i < sz; i++) 
		if (allData[i].year == yearWanted) {
		       yearData[x] = allData[i];
	       		count++;
	 		x++;
		}

return count;
}

void sortYearData(struct DailyData yearData[], int sz){
    //put your code here

  // sortYearData(yearData,numDays);
 int i, j, m;
 int tmp;

 for (i = 0; i < sz; i++) {
	 m = i;
	 for (j = i + 1; j < sz; j++)
		 if((yearData[j].month < yearData[m].month) || ((yearData[j].month == 
yearData[m].month) && (yearData[j].day < yearData[m].day))) {
			 m = j;
		 }
	 if (m != i) {
		 struct DailyData tmp = yearData[i];
		 yearData[i] = yearData[m];
		 yearData[m] = tmp;
			
	 }
 }


}

void getStats(int month, const struct DailyData yearData[],
                    int sz,struct MonthlyStatistic* monthly){

 //for(i=0;i<12;i++){
//        getStats(i+1,yearData,numDays,&monthly[i]);

//put your code here
// struct MonthlyStatistic monthly[12];

    int i;
    float maxTemp = 0;
    float lowTemp = 200;
    float avg = 0;
    float totalP = 0;   
    float sum = 0;
    int count = 0;
    

    for (i = 0; i < sz; ++i)
	if (yearData[i].month == month) {
	
	   if (yearData[i].high > maxTemp){
		 maxTemp = yearData[i].high;
	   }
           if (yearData[i].low < lowTemp){
		 lowTemp = yearData[i].low;
	   }
	   totalP += yearData[i].precipitation;
           sum += (yearData[i].high + yearData[i].low);
	   count++;
	}
	
	monthly->averageTemperature = (sum / count)/2;
        monthly->totalPrecipitation = totalP;
        monthly->maxTemperature = maxTemp;
        monthly->minTemperature = lowTemp;


}
void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly){
    

    const char *month_names[] = {"January", "February", "March", "April", "May", 
   "June", "July","August", "September", "October", "November", "December"};

printf(" %11s       | %.1f | %.1f | %.1f | %.1f     |\n",month_names[month - 1] , 
monthly->maxTemperature,monthly->minTemperature, monthly->averageTemperature, monthly->totalPrecipitation);

}

void graphLine(int month,const struct MonthlyStatistic* monthly){

   	//put your code here

//    for (i=0;i<12;i++){
  //      graphLine(i+1,&monthly[i]);



    const char *month_names[] = {"January", "February", "March", "April", "May",
   "June", "July","August", "September", "October", "November", "December"};

float total = 0;
char c = '*';
int i;

total =(int)monthly->totalPrecipitation; 

total /= 10;

printf("\n %10s |  ", month_names[month - 1]);


printf("%.1f",total);

for(i=0 ; i < total; i++)
putchar(c);


}
void printVerbose(const struct DailyData allData[],int sz){
    //put your code here

// printVerbose(yearData,numDays);


  const char *month_names[] = {"January", "February", "March", "April", "May",
   "June", "July","August", "September", "October", "November", "December"};

int i = 0;

for(i = 0; i <sz; i++) {

float avg = 0;
avg = (allData[i].high + allData[i].low) / 2;

if(allData[i].month == 1){
printf("January");}


if(allData[i].month == 2){
printf("February");}


if(allData[i].month == 3){
printf("March");}


if(allData[i].month == 4){
printf("April");}


if(allData[i].month == 5){
printf("May");}


if(allData[i].month == 6){
printf("June");}


if(allData[i].month == 7){
printf("July");}


if(allData[i].month == 8){
printf("August");}


if(allData[i].month == 9){
printf("September");}


if(allData[i].month == 10){
printf("October");}


if(allData[i].month == 11){
printf("November");}


if(allData[i].month == 12){
printf("December");}



printf("%d %d %.1f", allData[i].day, allData[i].year,
average(allData[i].high,allData[i].low));

draw(symbolToDraw(allData[i].condition, avg), 20);
putchar('\n');
} 
putchar('\n');


}
char symbolToDraw(char condition, float avgTemp){
    

         if ( condition == 's') {
                condition = '@';
         }
         else if (condition == 'c') { 
                 condition = '~';
         }
         else if (condition == 'p' && avgTemp >= 0) { 
                 condition = ';';
         }
         else if (condition == 'p' && avgTemp < 0) {
                 condition = '*';
         }

return condition;

}

float average(float first, float second){

float average = 0;
	average = (first + second) /2 ;
		
return average;
    
}

void draw( char c, int num ) {

	int count;

	for (count = 1; count <= num; count++){
           putchar(c);
        }
     
}






