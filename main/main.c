/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "dht11.h"
static const char *TAG = "main";

void app_main(void)
{
    set_dht_gpio(15);
    double temp = 0, hum = 0;
    while (1)
    {
        read_dht(&temp, &hum);

        ESP_LOGI(TAG, "T: %f, RH: %f", temp, hum);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}
