#include "MLX90614.h"

int lFd = 0;


void Hongwai::InitI2C()
{
    /* 初始化树莓派所有GPIO引脚*/
    wiringPiSetupSys();
    /* 启动树莓派I2C接口 */
    lFd = wiringPiI2CSetup(MLX90614_ADDRESS);
}

void Hongwai::gettemp()
{

    /* MLAX90614矫正 */
    MLAX90614_ReviseTempture(lFd);

    MLAX90614_ReadTempture(lFd);
//    delay(100);

}

/* MLAX90614矫正函数 */
void Hongwai::MLAX90614_ReviseTempture(int lFd)
{
    /* 发射率矫正，  MLAX90614一般默认是1， 人体的发射率为0.95 */
    wiringPiI2CWriteReg16 (lFd, MLX90614_REVISE_ADDR, MLX90614_REVISE_EMISSIVITY);  
}

/* MLAX90614温度读取 */
void Hongwai::MLAX90614_ReadTempture(int lFd)
{

    /* 读取物体及环境温度寄存器值 */
    lBodyRegData = wiringPiI2CReadReg16(lFd, MLX90614_REG_BODYDATA);
    lEnvRegData = wiringPiI2CReadReg16(lFd, MLX90614_REG_ENVIRONMENTDATA);
//    printf("Body reg data is %d\n", lBodyRegData);
//    printf("Environment reg data is %d\n", lEnvRegData);

    /* 将物体及环境温度寄存器值换算成实际温度值 */
    fBodyTempture = ((float)(lBodyRegData)*0.02)-273.15;
    fEnvTempture = ((float)(lEnvRegData)*0.02)-273.15;
//    printf("Body tempture is %f\n", fBodyTempture);
//    printf("Environment tempture is %f\n", fEnvTempture);
}





