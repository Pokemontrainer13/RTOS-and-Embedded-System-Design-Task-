# Virtual Sensor Module Datasheet

## Overview

The Virtual Sensor Module simulates a hardware sensor device.

The module generates periodic sensor measurements that can be used for testing FreeRTOS applications without requiring physical hardware.

---

# Initialization

Before reading data, the sensor module must be initialized.

## API

```c
void Sensor_Init(void);
```

### Description

Initializes the virtual sensor.

This function must be called once during system startup before any sensor readings are performed.

### Example

```c
Sensor_Init();
```

---

# Reading Sensor Data

Sensor data is retrieved using:

```c
SensorData_t Sensor_Read(void);
```

### Description

Returns the latest sensor measurement.

Each call generates a new sensor sample.

---

# Data Structure

```c
typedef struct
{
    uint32_t sensor_id;
    uint32_t timestamp;
    char description[512];
} SensorData_t;
```

---

# Field Descriptions

## sensor_id

```c
uint32_t sensor_id;
```

Unique identifier of the sensor that generated the sample.

Example:

```text
1
```

---

## timestamp

```c
uint32_t timestamp;
```

Monotonically increasing sample counter.

Each call to:

```c
Sensor_Read();
```

increments the timestamp.

Example:

```text
0
1
2
3
4
...
```

---

## description

```c
char description[512];
```

Text field associated with the sensor sample.

This field contains sensor metadata and descriptive information.

Example:

```text
AAAAAAAAAAAAAAAAAAAAAAAAAAAA...
```

Applications may transmit, store, or display this information.

---

# Example Usage

```c
Sensor_Init();

SensorData_t sample;

sample = Sensor_Read();

printf("Sensor ID: %u\n", sample.sensor_id);
printf("Timestamp: %u\n", sample.timestamp);
printf("Description: %s\n", sample.description);
```

---

# Example Output

```text
Sensor ID: 1
Timestamp: 0
Description: AAAAAAAAAAAAAAAAAAAAAAAAAAAAA...
```

Subsequent reads:

```text
Sensor ID: 1
Timestamp: 1

Sensor ID: 1
Timestamp: 2

Sensor ID: 1
Timestamp: 3
```

---

# Notes

* The sensor module is deterministic.
* The timestamp value increases on every call to `Sensor_Read()`.
* The sensor module does not require any hardware.
* The module is intended for software architecture and RTOS exercises.
