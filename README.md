# Embedded Systems Design and RTOS Learning Path

## Why Are We Doing This?

Many embedded projects begin as simple experiments and eventually grow into systems that are difficult to understand, debug, modify, or extend.

This repository was created to teach not only embedded programming, but also the engineering practices used to build maintainable and scalable systems.

The focus is not on memorizing APIs or learning a specific microcontroller.

The focus is on understanding how professional embedded systems are designed, organized, documented, debugged, and maintained.

---

## What Will You Gain?

By completing the modules in this repository, you will learn:

* How to structure embedded software into independent modules
* How to define clear responsibilities between components
* How to design maintainable system architectures
* How to use Git and documentation effectively
* How to reason about system behavior using state machines
* How to approach concurrency and RTOS-based systems
* How to design for debugging, testing, and future expansion
* How to think like an engineer rather than simply writing code that works

The objective is to build skills that remain useful across different hardware platforms, RTOSes, and projects.

---

## Why Does This Matter?

Many beginner projects eventually reach a point where adding a new feature becomes difficult because everything is tightly coupled together.

The examples below illustrate some common situations.

### From Monolithic Code to Modular Design

Instead of placing all functionality inside a single file:

```c
int main(void)
{
    OLED_Update();
    Encoder_Read();
    PID_Update();
    Motor_SetSpeed();
    USB_SendData();
}
```

we can separate responsibilities into dedicated modules:

```c
int main(void)
{
    Control_Update();
    Display_Update();
    Communication_Update();
}
```

---

### From Superloops to Concurrent Systems

A traditional superloop:

```c
while(1)
{
    ReadSensors();
    RunController();
    UpdateDisplay();
}
```

can eventually evolve into multiple independently scheduled tasks:

```c
SensorTask();
ControlTask();
DisplayTask();
```

---

### From Complex Conditions to State Machines

Instead of large chains of conditional logic:

```c
if(...)
{
}
else if(...)
{
}
else if(...)
{
}
```

we can model behavior explicitly:

```c
STATE_IDLE
STATE_RUNNING
STATE_ERROR
```

with well-defined transitions between states.

---

## How To Use This Repository

Modules are intended to be completed in order.

For each module:

1. Read the module README.
2. Understand the objective and background.
3. Complete any required setup.
4. Implement the assigned task or project.
5. Document your learning and observations.
6. Commit your work using Git.
7. Move to the next module.

Each module builds upon concepts introduced in previous modules.

---

## Philosophy

The goal is not to teach tricks.

The goal is to develop the ability to:

* Understand systems
* Design systems
* Maintain systems
* Debug systems
* Improve systems

The techniques used in this repository are tools that support those goals.

---

## A Final Note

No RTOS, framework, architecture pattern, or design methodology is magic.

Using an RTOS does not automatically make software better.

Creating more modules does not automatically improve architecture.

State machines do not automatically eliminate bugs.

Engineering decisions only become valuable when their purpose is understood.

The objective of this repository is to understand the reasoning behind those decisions and learn when they should be applied.

