#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a winter coat.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: No precautions needed.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}

int main() {
    float temperature, converted_temp;
    int current_scale, target_scale;
    
    while (1) {
        printf("Enter the temperature (or -1 to exit): ");
        scanf("%f", &temperature);

        if (temperature == -1) {
            break;
        }

        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &current_scale);

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &target_scale);

        if (current_scale < 1 || current_scale > 3 || target_scale < 1 || target_scale > 3) {
            printf("Invalid input.\n");
            continue;
        }
        
        if (current_scale == target_scale) {
            printf("Invalid conversion.\n");
            continue;
        }

        if (current_scale == 1 && target_scale == 2) {
            converted_temp = celsius_to_fahrenheit(temperature);
        } else if (current_scale == 1 && target_scale == 3) {
            converted_temp = celsius_to_kelvin(temperature);
        } else if (current_scale == 2 && target_scale == 1) {
            converted_temp = fahrenheit_to_celsius(temperature);
        } else if (current_scale == 2 && target_scale == 3) {
            converted_temp = fahrenheit_to_kelvin(temperature);
        } else if (current_scale == 3 && target_scale == 1) {
            converted_temp = kelvin_to_celsius(temperature);
        } else if (current_scale == 3 && target_scale == 2) {
            converted_temp = kelvin_to_fahrenheit(temperature);
        }

        if (target_scale == 1) {
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (target_scale == 2) {
            printf("Converted temperature: %.2f°F\n", converted_temp);
        } else {
            printf("Converted temperature: %.2fK\n", converted_temp);
        }

        float temp_in_celsius;
        if (target_scale == 1) {
            temp_in_celsius = converted_temp;
        } else if (target_scale == 2) {
            temp_in_celsius = fahrenheit_to_celsius(converted_temp);
        } else {
            temp_in_celsius = kelvin_to_celsius(converted_temp);
        }
        categorize_temperature(temp_in_celsius);
    }

    return 0;
}