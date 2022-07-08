//
// Created by Yang,Xi on 7/3/22.
//

#ifndef LEARN_COMPUTER_H
#define LEARN_COMPUTER_H
#include "string"
#include "iostream"

using namespace std;

class RAM {
public:
    int * rsize;
    virtual void storage() = 0;

    RAM() {
        printf("create RAM\n");
    }

    virtual ~RAM() {
        printf("release rsize in RAM\n");
    }

};

class GPU {
public:
    virtual void display() = 0;
    virtual ~GPU() = default;
};

class CPU {
public:
    virtual void calculate() = 0;
};

class IntelCPU : public CPU {
public:
    void calculate() override {
        printf("intel CPU do calculation\n");
    }
};

class AMDCPU : public CPU {
public:
    void calculate() override {
        printf("AMD CPU do calculation\n");
    }
};

class IntelGPU : public GPU {
public:
    void display() override {
        printf("intel GPU do display\n");
    }

    ~IntelGPU() override = default;
};

class NVGPU : public GPU {
public:
    void display() override {
        printf("NV GPU do display\n");
    }

    ~NVGPU() override = default;
};

class IntelRAM : public RAM {
public:
    void storage() override {
        printf("intel RAM do storage with %d\n", * this->rsize);
    }

    explicit IntelRAM(int rsize) {
        printf("create intel ram\n");
        this->rsize = new int(rsize);
    }

    ~IntelRAM() override {
        printf("release size in intelram\n");
        delete this->rsize;
        this->rsize = nullptr;
    }
};

class SumsangRAM : public RAM {
public:
    void storage() override {
        printf("Sumsang RAM do storage with %d\n", * this->rsize );
    }

    explicit SumsangRAM(int rsize) {
        printf("create Sumsang ram\n");
        this->rsize = new int(rsize);
    }

    ~SumsangRAM() override {
        printf("release size in SumsangRAM\n");
        delete this->rsize;
        this->rsize = nullptr;
    }
};

class computer {
public:
    CPU * cpu;
    GPU * gpu;
    RAM * ram;

    computer(CPU * cpu, GPU * gpu, RAM * ram) {
        this->cpu = cpu;
        this->gpu = gpu;
        this->ram = ram;
    }

    ~computer(){
        delete this->cpu;
        delete this->gpu;
        delete this->ram;

        this->cpu = nullptr;
        this->gpu = nullptr;
        this->ram = nullptr;
    }

    void doWork() {
        this->cpu->calculate();
        this->gpu->display();
        this->ram->storage();
    }
};

void testComputer() {
    auto * intelCpu = new IntelCPU;
    auto * intelGpu = new IntelGPU;
    auto * intelRam = new IntelRAM(10);

    auto * cpt =  new computer(intelCpu, intelGpu, intelRam);
    cpt->doWork();
    delete cpt;

    auto * amdCpu = new AMDCPU;
    auto * nvGpu = new NVGPU;
    auto * sram = new SumsangRAM(20);

    cpt =  new computer(amdCpu, nvGpu, sram);
    cpt->doWork();
    delete cpt;
}


#endif //LEARN_COMPUTER_H
