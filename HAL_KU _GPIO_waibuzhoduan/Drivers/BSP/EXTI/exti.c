#include "./BSP/EXTI/exti.h"
#include "./SYSTEM/delay/delay.h"
void exti_init(void)
{
    GPIO_InitTypeDef gpio_init_truct;
    
    __HAL_RCC_GPIOE_CLK_ENABLE();
    
    gpio_init_truct.Pin=GPIO_PIN_4;
    gpio_init_truct.Mode=GPIO_MODE_IT_FALLING;
    gpio_init_truct.Pull=GPIO_PULLUP;
    
    HAL_GPIO_Init(GPIOE,&gpio_init_truct);
    HAL_NVIC_SetPriority(EXTI4_IRQn,2,0);
    HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}

void EXTI4_IRQHandler(void)
{

        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

    delay_ms(20);
    if (GPIO_Pin==GPIO_PIN_4)
    {
       if (HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4)==0)
       {
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_5);
       }
       
    }
    



}


