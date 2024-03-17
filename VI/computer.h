#ifndef LAB_WORKS_2_COMPUTER_H
#define LAB_WORKS_2_COMPUTER_H
#define MAX_LENGTH 20

typedef enum {
    Builtin,
    External,
    AGP,
    PCI
} vc;

typedef enum {
    SCSI_IDE,
    ATA_SATA
} vmt;

typedef struct {
    char *name;
    int number_of_processors;
    char *type_of_processors;
    int memory_capacity;
    vc video_controller;
    int video_memory_capacity;
    vmt video_memory_type;
    int number_of_hard_drives;
    int capacity_of_hard_drives;
    int number_of_integrated_controllers;
    int number_of_external_devices;
    char *os;
} Computer;

Computer *input_computer(void);
#endif