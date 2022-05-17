#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

#define MD_W_MACRO_CNT      48
#define MD_H_MACRO_CNT      27
#define MD_MACRO_CNT        ((MD_W_MACRO_CNT)*(MD_H_MACRO_CNT))

#define MD_MACRO_VAL \
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

#define MD_MACRO_VAL2 \
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,\
	0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,\
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	1,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,\
	0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,\
	1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

// 8邻域相对位置relative position
int16_t relPos8[8] = {
	-((MD_W_MACRO_CNT)+1), -(MD_W_MACRO_CNT), -((MD_W_MACRO_CNT)-1),
	        -1,                /* pos */               1,
	 ((MD_W_MACRO_CNT)-1),   MD_W_MACRO_CNT,   ((MD_W_MACRO_CNT)+1)
};


#if 1

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define  MD_AREA_MAX_NUM  (32) // (64)

typedef struct
{
    uint32_t topLeftX; 	/*!< 矩形区域左上点水平方向上的坐标 */
    uint32_t topLeftY; 	/*!< 矩形区域左上点垂直方向上的坐标 */
    uint32_t butRightX; /*!< （用于内部计算，一般不对外开放！！）矩形区域右下点水平方向上的坐标 */
    uint32_t butRightY; /*!< （用于内部计算，一般不对外开放！！）矩形区域右下点垂直方向上的坐标 */
    uint32_t width;     /*!< 矩形区域的宽度 */
    uint32_t height;    /*!< 矩形区域的高度 */
}Rect_t;


typedef struct
{
    uint32_t boxNum;
    Rect_t box[MD_AREA_MAX_NUM];
} MdResult_t;


#endif

void printBuf(uint8_t *buf, uint32_t width, uint32_t height)
{
	int i, j, index;

	printf("\nFrameMACRO:\n");
	printf("  ");
	for (i = 0; i < width; i++)
	{
		printf("%2d ", i);
	}
	for (i = 0; i < height; i++)
	{
		printf("\n\r%2d", i);
		for (j = 0; j < width; j++)
		{
			index = i * width + j;
			printf(" %c ", buf[index] ? 'o' : ' ');
		}
	}
	printf("\n\n");
}

void printBuf2(uint8_t *buf, uint32_t width, uint32_t height)
{
	int i, j, index;

	printf("\nFrameMACRO:\n");
	printf("  ");
	for (i = 0; i < width; i++)
	{
		printf("%2d ", i);
	}
	for (i = 0; i < height; i++)
	{
		printf("\n\r%2d", i);
		for (j = 0; j < width; j++)
		{
			index = i * width + j;
			printf("%2d ", buf[index]);
		}
	}
	printf("\n\n");
}


void markNeighbours(uint8_t *mdMacroData, uint32_t width, uint32_t height, uint16_t position, uint8_t markVal)
{
	/* 标记 */
	mdMacroData[position] = markVal;

    /* 8邻域查找并递归 */
	for (int i = 0; i < 8; i++)
	{
		if ((position + relPos8[i]) >= 0 && \
			(position + relPos8[i]) < width*height && \
			(mdMacroData[position + relPos8[i]] == 1))
		{
			markNeighbours(mdMacroData, width, height, (position + relPos8[i]), markVal);
		}
	}
	return;	
}

int binConnectAlgo(uint8_t *mdMacroData, uint32_t width, uint32_t height, MdResult_t *outMdResult)
{
	int i, j;
	uint8_t markVal = 2; // 标记从2开始改，因为二值就是0/1
	uint8_t val = 0;
	uint32_t index = 0; 
	uint32_t mdBoxMaxNum = 0;

	if (!mdMacroData || !width || !height || !outMdResult)
	{
		printf("[%s:%d]: invalid argument!\n", __FUNCTION__, __LINE__);
		return -1;
	}

	/* 0. 先算出传出去最大支持多少个框 */
	mdBoxMaxNum = sizeof(outMdResult->box)/sizeof(outMdResult->box[0]);

	/* 1. 修改数据源：0/1 => 0/2/3/4... 其实这一步算法就已经得到结构了，后面的步骤自己根据实际需要处理数据而已 */
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			index = i*width + j;

			if (mdMacroData[index] == 1)
			{
				markNeighbours(mdMacroData, width, height, index, markVal);
				markVal++;
			}
		}
	}

	/* 2. 调整数据源：0/2/3/4... => 0/1/2/3...（如果考虑耗时，这一步可以去掉，相对地，后面的步骤也需要调整） */
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			index = i*width + j;

			if (mdMacroData[index] != 0)
			{
				mdMacroData[index] = mdMacroData[index] - 1;
			}
		}
	}

	/* 3. 算出框的位置 */
	/* 3.1 先初始化 */
	outMdResult->boxNum = 0;
	for (i = 0; i < mdBoxMaxNum; i++)
	{
		outMdResult->box[i].topLeftX = width;
		outMdResult->box[i].topLeftY = height;
		outMdResult->box[i].butRightX = 0;
		outMdResult->box[i].butRightY = 0;
	}

	/* 3.2 再计算结左上角&右下角的坐标 */
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			index = i*width + j;
			val = mdMacroData[index];

			if (val >= 2 && val < mdBoxMaxNum + 2)
			{
				outMdResult->boxNum = MAX(outMdResult->boxNum, val-1);
				outMdResult->box[val-2].topLeftX = MIN(outMdResult->box[val-2].topLeftX, j);
				outMdResult->box[val-2].topLeftY = MIN(outMdResult->box[val-2].topLeftY, i);
				outMdResult->box[val-2].butRightX = MAX(outMdResult->box[val-2].butRightX, j);
				outMdResult->box[val-2].butRightY = MAX(outMdResult->box[val-2].butRightY, i);
			}
		}
	}

	/* 3.3 根据左上角&右下角的坐标计算框的宽度及高度（注：宽度和高度是不能在3.2的统计过程得到的） */
	for (i = 0; i < outMdResult->boxNum; i++)
	{
		outMdResult->box[i].width  = outMdResult->box[i].butRightX - outMdResult->box[i].topLeftX + 1;
		outMdResult->box[i].height = outMdResult->box[i].butRightY - outMdResult->box[i].topLeftY + 1;
	}

	return 0;
}

int main(void)
{
	uint8_t mdMacroData[MD_MACRO_CNT] = {MD_MACRO_VAL2};
	uint32_t width = MD_W_MACRO_CNT;
	uint32_t height = MD_H_MACRO_CNT;
	MdResult_t mdResult = {0};
	struct timeval t1, t2;

	printBuf(mdMacroData, width, height);

	gettimeofday(&t1, NULL);
	binConnectAlgo(mdMacroData, width, height, &mdResult);
	gettimeofday(&t2, NULL);

	printBuf2(mdMacroData, width, height);

	if (mdResult.boxNum > 0)
	{
		for (int i = 0; i < mdResult.boxNum; ++i)
		{
			printf("Box[%d] - x: %2d  y:%2d  w: %2d  h: %2d\n", i, mdResult.box[i].topLeftX, mdResult.box[i].topLeftY,
															mdResult.box[i].width, mdResult.box[i].height);
		}
	}


	printf("take time: %lu ms (%lu us)\n", (t2.tv_sec-t1.tv_sec)*1000+(t2.tv_usec-t1.tv_usec)/1000,
										   (t2.tv_sec-t1.tv_sec)*1000000+(t2.tv_usec-t1.tv_usec));
	return 0;
}

