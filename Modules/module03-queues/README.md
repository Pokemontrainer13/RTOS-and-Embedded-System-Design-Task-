# Module 03 - FreeRTOS Queues

## Introduction

In the previous module, each task executed independently.

While independent tasks are useful, real embedded systems often require tasks to exchange information.

Examples:

```text
Sensor Task
    ↓
Control Task

Control Task
    ↓
Motor Task

Telemetry Task
    ↓
Logger Task
```

FreeRTOS provides Queues for safe communication between tasks.

---

# What Is a Queue?

A queue is a First In First Out (FIFO) data structure.

The first item inserted into the queue is the first item removed from the queue.

Example:

```text
Queue

+-------+
| Item1 |
+-------+
| Item2 |
+-------+
| Item3 |
+-------+

Receive

Item1
Item2
Item3
```

---

# Why Use Queues?

Without queues, tasks would need to share global variables.

Example:

```c
int sensorValue;
```

This can create problems:

* Data corruption
* Race conditions
* Difficult debugging

Queues provide a safe mechanism for transferring data between tasks.

---

# Producer and Consumer

A common queue architecture consists of:

```text
Producer Task
        ↓
      Queue
        ↓
Consumer Task
```

Example:

```text
SensorTask
        ↓
      Queue
        ↓
DisplayTask
```

The producer generates data.

The consumer receives and processes data.

---

# Creating a Queue

Queues are created using:

```c
xQueueCreate()
```

Example:

```c
QueueHandle_t sensorQueue;

sensorQueue = xQueueCreate(
                    5,
                    sizeof(uint32_t));
```

Parameters:

```text
5                 Number of queue entries
sizeof(uint32_t)  Size of each entry
```

This queue can hold:

```text
5 uint32_t values
```

---

# Sending Data

Data is sent to a queue using:

```c
xQueueSend()
```

Example:

```c
uint32_t sensorValue = 123;

xQueueSend(
    sensorQueue,
    &sensorValue,
    portMAX_DELAY);
```

Parameters:

```text
Queue Handle
Pointer to data
Block time
```

---

# Receiving Data

Data is received using:

```c
xQueueReceive()
```

Example:

```c
uint32_t sensorValue;

xQueueReceive(
    sensorQueue,
    &sensorValue,
    portMAX_DELAY);
```

The received value is copied into:

```c
sensorValue
```

---

# Blocking Behaviour

Queues can block tasks.

Example:

```c
xQueueReceive(
    queue,
    &data,
    portMAX_DELAY);
```

If the queue is empty:

```text
Task
    ↓
Blocked
    ↓
Waits for data
```

When data arrives:

```text
Task
    ↓
Ready
    ↓
Running
```

This allows efficient CPU utilization.

---

# Queue Data Copying

A very important concept:

Queues copy data.

Example:

```c
uint32_t value = 100;

xQueueSend(
    queue,
    &value,
    portMAX_DELAY);
```

The value is copied into queue storage.

The queue does not store a reference to the variable.

---

# Typical Embedded Use Cases

Examples:

```text
Sensor Task
    ↓
Control Task
```

```text
Communication Task
    ↓
Logger Task
```

```text
Button Task
    ↓
User Interface Task
```

```text
Telemetry Task
    ↓
Storage Task
```

---

# Common Queue APIs

Create Queue

```c
xQueueCreate()
```

Send Data

```c
xQueueSend()
```

Receive Data

```c
xQueueReceive()
```

Send From ISR

```c
xQueueSendFromISR()
```

Receive From ISR

```c
xQueueReceiveFromISR()
```

Delete Queue

```c
vQueueDelete()
```

---

# Queue Workflow

Typical workflow:

```text
Create Queue
        ↓
Create Producer Task
        ↓
Create Consumer Task
        ↓
Send Data
        ↓
Receive Data
        ↓
Process Data
```

---

# Learning Outcomes

After completing this module, learners should understand:

* Why queues are needed
* Producer-consumer architecture
* FIFO behaviour
* Queue creation
* Sending data
* Receiving data
* Blocking on queues
* Inter-task communication using FreeRTOS

```
```
