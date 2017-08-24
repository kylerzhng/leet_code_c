#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target) {
	struct hash_node {
		int value;
		struct hash_node* next;
	};

	struct hash_node* hash_table = malloc(sizeof(struct hash_node)*(numsSize+1));
	int i,j;
	int hash_key;
	int bingo = 0;
	int hash_key1;
	int *out = malloc(sizeof(int)*2);
	int number;
	int hash_value;
	struct hash_node* head;
	struct hash_node* node;

	if (!hash_table)
		return NULL;

//	printf("numsSize:%d\n",numsSize);
	for (i=0;i<=numsSize;i++) {
		hash_table[i].value = -1;
		hash_table[i].next = NULL;
	}

	for (i=0;i<numsSize;i++) {

		number = nums[i];
		

		hash_key = abs(target - number) % numsSize;
		hash_key1 = abs(number % numsSize);

//		printf("index:%d target:%d number:%d hash_value1:%d hash_value:%d\n",i,target,number,hash_table[hash_key1].value,hash_table[hash_key].value);

		if (hash_table[hash_key1].value != -1) {
			head = &hash_table[hash_key1];
			while (head) {
				hash_value = head->value;
				if (nums[hash_value] == (target-number)) {
					bingo = 1;
					break;
				}
				head = head->next;
			}
			if (bingo)
				break;
			else
				goto write_hash;
		} else {
write_hash:
			head = &hash_table[hash_key];
			if (head->value != -1) {
				while (head->next) {
					head = head->next;
				}
				node = malloc(sizeof(struct hash_node));
				node->value = i;
				node->next = NULL;
				head->next = node;
//				printf("index:%d write:key:%d value:%d\n",i,hash_key,i);
			} else {
				head->value = i;
//				printf("index:%d write: key1:%d value:%d\n",i,hash_key,i);
			}
		}
	}

	if (bingo) {
		j = hash_value;
		out[0] = j;
		out[1] = i;
	} else {
		printf("error\n");
	}
	for(i=0;i<=numsSize;i++) {
			head = &hash_table[i];
			while (head && head->next) {
				head = head->next->next;
				free(head);
			}
		}
	free(hash_table);
	return out;
}


int main(int argc, char* argv[])
{
	int arrary[] = {572,815,387,418,434,530,376,190,196,74,830,561,973,771,640,37,539,369,327,51,623,575,988,44,659,48,22,776,487,873,486,169,499,82,128,31,386,691,553,848,968,874,692,404,463,285,745,631,304,271,40,921,733,56,883,517,99,580,55,81,232,971,561,683,806,994,823,219,315,564,997,976,158,208,851,206,101,989,542,985,940,116,153,47,806,944,337,903,712,138,236,777,630,912,22,140,525,270,997,763,812,597,806,423,869,926,344,494,858,519,389,627,517,964,74,432,730,843,673,985,819,397,607,34,948,648,43,212,950,235,995,76,439,614,203,313,180,760,210,813,920,229,615,730,359,863,678,43,293,978,305,106,797,769,3,700,945,135,430,965,762,479,152,121,935,809,101,271,428,608,8,983,758,662,755,190,632,792,789,174,869,622,885,626,310,128,233,82,223,339,771,741,227,131,85,51,361,343,641,568,922,145,256,177,329,959,991,293,850,858,76,291,134,254,956,971,718,391,336,899,206,642,254,851,274,239,538,418,21,232,706,275,615,568,714,234,567,994,368,54,744,498,380,594,415,286,260,582,522,795,261,437,292,887,405,293,946,678,686,682,501,238,245,380,218,591,722,519,770,359,340,215,151,368,356,795,91,250,413,970,37,941,356,648,594,513,484,364,484,909,292,501,59,982,686,827,461,60,557,178,952,218,634,785,251,290,156,300,711,322,570,820,191,755,429,950,18,917,905,905,126,790,638,94,857,235,889,611,605,203,859,749,874,530,727,764,197,537,951,919,24,341,334,505,796,619,492,295,380,128,533,600,160,51,249,5,837,905,747,505,82,158,687,507,339,575,206,28,29,91,459,118,284,995,544,3,154,89,840,364,682,700,143,173,216,290,733,525,399,574,693,500,189,590,529,972,378,299,461,866,326,43,711,460,426,947,391,536,26,579,304,852,158,621,683,901,237,22,225,59,52,798,262,754,649,504,861,472,480,570,347,891,956,347,31,784,581,668,127,628,962,698,191,313,714,893};
//	int arrary[] = {150,24,79,50,88,345,3};
//	int arrary[] ={230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
	int len = sizeof(arrary)/sizeof(int);
//	int* buff = twoSum(arrary,len,542);
//	int* buff = twoSum(arrary,len,200);
	int* buff = twoSum(arrary,len,101);

	if (buff)
		printf("%d:%d %d:%d\n",buff[0],arrary[buff[0]],buff[1],arrary[buff[1]]);
	free(buff);
	return 0;	
}
