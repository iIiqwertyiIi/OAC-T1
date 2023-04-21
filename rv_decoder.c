//
// Created by iiiqwertyiii on 4/21/23.
//
#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t RI, funct7, funct3, opcode, rd, rs1, rs2, shamt;
    int32_t imm32;

    uint32_t b7_mask = 0x7F;
    uint32_t b5_mask = 0x1F;
    uint32_t b3_mask = 0x7;
    uint32_t b11_mask = 0xFFE00000;
    uint32_t b7_mask2 = 0xFE000000;

    uint32_t tmp1;
    int32_t tmp2;

    scanf("%x", &RI);

    opcode = RI & b7_mask;

    switch(opcode) {
        case 0x33:
            rd = (RI >> 7) & b5_mask;
            funct3 = (RI >> 12) & b3_mask;
            rs1 = (RI >> 15) & b5_mask;
            rs2 = (RI >> 20) & b5_mask;
            funct7 = (RI >> 25) & b7_mask;

            printf("opcode: %x\nrd: %x\nfunct3: %x\nrs1: %x\nrs2: %x\nfunct7: %x\n", opcode, rd, funct3, rs1, rs2, funct7);

            break;

        case 0x67:
            rd = (RI >> 7) & b5_mask;
            funct3 = (RI >> 12) & b3_mask;
            rs1 = (RI >> 15) & b5_mask;
            imm32 = (RI & b11_mask);
            imm32 = imm32 >> 20;

            printf("opcode: %x\nrd: %x\nfunct3: %x\nrs1: %x\nimm32: %x\n", opcode, rd, funct3, rs1, imm32);

            break;

        case 0x3:
            rd = (RI >> 7) & b5_mask;
            funct3 = (RI >> 12) & b3_mask;
            rs1 = (RI >> 15) & b5_mask;
            imm32 = (RI & b11_mask);
            imm32 = imm32 >> 20;

            printf("opcode: %x\nrd: %x\nfunct3: %x\nrs1: %x\nimm32: %x\n", opcode, rd, funct3, rs1, imm32);

            break;

        case 0x13:
            funct3 = (RI >> 12) & b3_mask;
            if(funct3 == 0x1 || funct3 == 0x5) {
                rd = (RI >> 7) & b5_mask;
                rs1 = (RI >> 15) & b5_mask;
                shamt = (RI >> 20) & b5_mask;
                funct7 = (RI >> 25) & b7_mask;

                printf("opcode: %x\nrd: %x\nfunct3: %x\nrs1: %x\nshamt: %x\nfunct7: %x\n", opcode, rd, funct3, rs1, shamt, funct7);
            }
            else {
                rd = (RI >> 7) & b5_mask;
                rs1 = (RI >> 15) & b5_mask;
                imm32 = (RI & b11_mask);
                imm32 = imm32 >> 20;
                imm32 += 0x1;

                printf("opcode: %x\nrd: %x\nfunct3: %x\nrs1: %x\nimm32: %x\n", opcode, rd, funct3, rs1, imm32);
            }
            break;

        case 0x23:
            tmp1 = (RI >> 7) & b5_mask;
            tmp2 = RI & b7_mask2;
            tmp2 = tmp2 >> 20;
            imm32 = tmp1 + tmp2;
            funct3 = (RI >> 12) & b3_mask;
            rs1 = (RI >> 15) & b5_mask;
            rs2 = (RI >> 20) & b5_mask;

            printf("opcode: %x\nfunct3: %x\nrs1: %x\nrs2: %x\nimm32: %x\n", opcode, funct3, rs1, rs2, imm32);
            
            break;
    }

    return 0;
}