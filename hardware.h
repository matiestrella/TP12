/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hardware.h
 * Author: matias
 *
 * Created on 4 de noviembre de 2020, 13:42
 */

#ifndef HARDWARE_H
#define HARDWARE_H

#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>


void export_pin22 (void);
void set_pin22_output(void);
void set_pin22 (void);

#endif HARDWARE_H 

