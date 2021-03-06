#include "sys.h"
#include "usart.h"	
////////////////////////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_UCOS
#include "includes.h"					//ucos 使用	  
#endif

////////////////////////////////////////////////////////////////////////////////////////////
// 文   件   名  : CassSysVar.h
// 版        本  :                            
// 目的及主要功能: CRC校验码的存放数组存声明，在内部RAM较小的CPU中可以考虑存放在Flash中
// 创 建 日  期  : 2008.3.5
// 修 改 日  期  : 2008.3.5                    
// 作        者  : hfl
// 修   改   者  :                      
////////////////////////////////////////////////////////////////////////////////////////////
/* CRC高位字节值表*/ 
const u8 CRCHi[256] = { 

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 

0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 

0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 

0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 

0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 

0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 

0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 

0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 

0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 

0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 

0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 

0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 

0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 

0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 

0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 

0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 

0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 

0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 

0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 

0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 

0x80, 0x41, 0x00, 0xC1, 0x81, 0x40 

};


/* CRC低位字节值表*/ 
const u8 CRCLo[256] = { 

0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 

0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 

0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 

0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 

0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 

0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 

0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 

0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 

0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 

0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 

0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 

0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 

0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 

0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 

0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 

0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 

0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 

0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 

0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 

0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 

0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 

0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 

0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 

0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 

0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 

0x43, 0x83, 0x41, 0x81, 0x80, 0x40 

};

#define USART_REC_LEN 64
#define USART_REC_TIME_COUNT 10
//#define USART_SND_LEN 1024  //76800 + modbus format

u8 ComDelayCount = USART_REC_TIME_COUNT;
u8 ComInBuf[USART_REC_LEN];
//u8 ComOutBuf[USART_SND_LEN];
u8 ComOutBuf[USART_SND_LEN];
u8 *pComInBuf = ComInBuf;
u8 *pComOutBuf = ComOutBuf;

u16 ComInDataLen = 0;
//u8 ComInDataPos = 0;
u32 ComOutDataLen = 0;
u32 ComOutDataPos = 0;

extern u16 cass_mv_boarder_width;
extern u16 cass_mv_boarder_height;
extern u16 snd_buf_len;
extern u8 raw_data[];
extern u8 out_data[];
extern u8 CassMem[];
extern u8 sensor_id;
extern u8 update_outbuf_flag;
extern u16 ComOutDelay;
extern u16 USARTEndDelay;


void USART2_IRQHandler(void)
{
	if(USART2->SR&(1<<5)) 			//接收中断		
	{
     USART2->SR &= ~(1<<5);  //USART_ClearITPendingBit(USART2, USART_IT_TC); 
		if(ComInDataLen < USART_REC_LEN )
		{
			pComInBuf[ComInDataLen] = USART2->DR;    
			ComInDataLen++;
			ComDelayCount = USART_REC_TIME_COUNT;
		}	 
	}
	if(USART2->SR&(1<<6))//可以发送下一个数据
	{	 
		USART2->SR &= ~(1<<6);
		if(ComOutDataPos < ComOutDataLen)
		{
			USART2->DR=pComOutBuf[ComOutDataPos];
			ComOutDataPos++;	
		}
		else
		{
			USARTOverTimeHandle();
			//USARTEndDelay = 5;
		}
	}		
} 



void memcpy(u8 *str,u8 *copystr,u32 len)
{
  u32 i;
  for(i = 0;i < len;i++)
    str[i] = copystr[i];
}


//用于得到相应的CRC校验码，不需修改
u16 GetCRC(u8 *Array,u8 DataCount )
{
	u8 index;
	u8 i;
	u8 CRCHigh,CRCLow ;

	//Array为数组首地址,DataCount为数据长度

	CRCHigh = 0xFF;
	CRCLow = 0xFF;

	for(i=0; i<DataCount; i+=1 )
	{
		index = CRCHigh ^ ( *(Array + i) );
		CRCHigh = CRCLow ^ CRCHi[index];
		CRCLow = CRCLo[index];
	}

	return ( CRCHigh << 8 ) | CRCLow ;
}


//======================================================================
// 函 数 名： COMFrmVrify
// 功能描述： 接受帧校验
// 输入参数： 待校验的数组首地址，长度
// 输出参数： 1为校验正确，0校验失败
// 创建日期： 2007.6.18
// 修改日期： 2008.3.5
// 作    者： john
// 修 改 者:  hfl  
// 附加说明： 
//======================================================================
u8 COMFrmVrify(u8 *Array, u8 DataCount)
{
	u16 verify,temp;

	//校验码 CRC校验
	verify = GetCRC(Array,DataCount - 2 ) ;

	temp =  Array[DataCount - 1] | (Array[DataCount - 2] << 8);
	if ( verify == temp ) 	return 1;
	else return 0 ;
}



void UartSendData()
{                                                                            
	 pComInBuf[1]=0x00;
	 GPIOB->BSRR = 0x0002;
	 ComOutDelay = 1000000;
	 ComOutDataPos = 0;
	 USART2->CR1 &= ~(1<<5);
	 USART2->CR1 |= 1<<6; //重新使能发送中断
	 USART2->SR &= ~(1<<6);
	 USART2->DR=pComOutBuf[ComOutDataPos];
	 ComOutDataPos++;
// 	 ComOutDataPos = 0;
// 	 USART1->CR1 |= 1<<7; //重新使能发送中断
}


//======================================================================
// 函 数 名： UartSlaveDataHandle
// 功能描述： 串口主机接受帧函数
// 输入参数： void
// 输出参数： void
// 创建日期： 2007.6.18
// 修改日期： 2008.3.5
// 作    者： john
// 修 改 者:  hfl  
// 附加说明： 通过全局指针交换数据
//======================================================================
void UartRecvDataHandle() //标准MOD-BUD
{
	u16 usTemp ;
	u16 tmp ;
	s32 left_size;

	tmp = pComInBuf[3]  + (pComInBuf[2]<< 8)  ;  //内存地址
	//根据接收帧构造发送帧并启动发送
	pComOutBuf[0]=pComInBuf[0] ; //sensor_id
	pComOutBuf[1]=pComInBuf[1] ;
	if ( pComInBuf[1] == 0x03 ) // 上位机发的读数据命令
	{	
		usTemp = pComInBuf[5]<<1; //字节个数
		pComOutBuf[2] = usTemp;
		memcpy(pComOutBuf+3, tmp+ CassMem ,usTemp ) ;
		ComOutDataLen =usTemp + 5 ;
	}
	else if (pComInBuf[1] == 0x06)	//写命令
	{
		//usTemp = pComInBuf[5]<<1; //字节个数
		memcpy(tmp+ CassMem, pComInBuf+ 4, 2) ; //数据拷贝到内存区
		memcpy(pComOutBuf,pComInBuf,8) ;
		ComOutDataLen = 8 ;
		
	}
	else if ( pComInBuf[1] == 0x10 )
	{
		usTemp = pComInBuf[6];//字节个数
		memcpy(tmp+ CassMem, pComInBuf+ 7, usTemp ) ; //数据拷贝到内存区
		memcpy(pComOutBuf,pComInBuf,6) ;
		ComOutDataLen = 8 ;
	}
	else if ( pComInBuf[1] == 0x20 )
	{
		if(tmp == 0)
			 update_outbuf_flag = 0;
		
		if(tmp * UART_SND_BLK_SIZE > snd_buf_len)
		{
			return;
		}
		
		//memcpy((u8 *)&usTemp, (u8 *)(out_data+tmp*UART_SND_BLK_SIZE+4),2);
		left_size = (s32)(snd_buf_len - tmp*UART_SND_BLK_SIZE);
		if(left_size < 0)
		{
			  return;
		}
		else
		{
			 if(left_size - UART_SND_BLK_SIZE >= 0)
				  usTemp = UART_SND_BLK_SIZE;
			 else
				  usTemp = (u16)left_size;
		}

		memcpy(pComOutBuf, (u8 *)(out_data+tmp*UART_SND_BLK_SIZE), usTemp);
		if(snd_buf_len == (tmp * UART_SND_BLK_SIZE + usTemp))
			update_outbuf_flag = 1;
		ComOutDataLen = usTemp;
		
		return;
	}
	
	usTemp = GetCRC(pComOutBuf,ComOutDataLen - 2 ) ;
	pComOutBuf[ComOutDataLen - 1] = usTemp ;			//返回帧尾
	pComOutBuf[ComOutDataLen - 2] = usTemp >> 8 ;
} 

//======================================================================
// 函 数 名： UART0RecvHandle
// 功能描述： 串口处理接受帧函数
// 输入参数： ComNo:串口号
// 输出参数： void
// 创建日期： 2007.6.18
// 修改日期： 2008.3.5
// 作    者： john
// 修 改 者:  hfl  
// 附加说明： 通过全局指针交换数据
//======================================================================
void UartRecvHandle(u8 ComNo)
{
	u8 crcFlag;
	

	if(pComInBuf[0] == sensor_id)
	{
		crcFlag = COMFrmVrify(pComInBuf, ComInDataLen) ; //	
		 //为下次接收作准备
		if (!crcFlag )	// 数据校验错误
		{
			ComInDataLen = 0;
 			return;
		}
		UartRecvDataHandle() ;
		UartSendData();//启动发送过程,需修改为具体代码

	}
			ComInDataLen = 0; //为下次接收作准备
	
}

//初始化IO 串口1
//pclk2:PCLK2时钟频率(Mhz)
//bound:波特率
//CHECK OK
//091209
void uart_init(u32 pclk2,u32 bound)
{  	 
	float temp;
	u16 mantissa;
	u16 fraction;
	
	temp=(float)(pclk2)/(bound*16);//得到USARTDIV
	mantissa=temp;				 //得到整数部分
	fraction=(temp-mantissa)*16; //得到小数部分	 
    mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<3;   //使能PORTB口时钟
	RCC->APB2ENR|=1<<2;   //使能PORTA口时钟  
	 
	RCC->APB1ENR|=1<<17;  //使能串口时钟 
	GPIOA->CRL&=0XFFFF00FF;//IO状态设置
	GPIOA->CRL|=0X00008B00;//IO状态设置

	GPIOB->CRL&=0XFFFFFF0F;//IO状态设置
	GPIOB->CRL|=0X00000010;//IO状态设置

	GPIOB->CRH&=0XFFFF0FFF;//IO状态设置
	GPIOB->CRH|=0X00001000;//IO状态设置
		  
	RCC->APB1RSTR|=1<<17;   //复位串口1
	RCC->APB1RSTR&=~(1<<17);//停止复位	   	   
	//波特率设置
 	USART2->BRR=mantissa; // 波特率设置	 
	USART2->CR1|=0X200C;  //1位停止,无校验位.

	//使能接收中断
	//USART2->CR1|=1<<8;    //PE中断使能
	USART2->CR1|=1<<5;    //接收缓冲区非空中断使能	    	
	
	//USART1->CR1|=1<<7;    
	USART2->SR&=~(1<<6);    //TXE发送缓冲区空中断使能	
	
	MY_NVIC_Init(3,3,USART2_IRQChannel,2);//组2，最低优先级 
}

void USARTOverTimeHandle(void)
{
	USART2->CR1 &= ~(1<<6);
			
	GPIOB->BSRR = 0x0000;	//RS485接收
	GPIOB->BRR = 0x0002;
	USART2->CR1 |= (1<<5);
	USART2->SR &= ~(1<<6);
	USART2->SR &= ~(1<<5);
	ComOutDataPos = 0 ;
	ComOutDataLen = 0 ;
	ComInDataLen = 0;
	ComOutDelay = 0;
}