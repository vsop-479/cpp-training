//
// Created by zhouhui on 2021/12/31.
//
#include "stdio.h"

enum ibv_wc_opcode {
//    0
    IBV_WC_SEND,
//    1
    IBV_WC_RDMA_WRITE,
    IBV_WC_RDMA_READ,
    IBV_WC_COMP_SWAP,
    IBV_WC_FETCH_ADD,
    IBV_WC_BIND_MW,
    IBV_WC_LOCAL_INV,
    IBV_WC_TSO,
/*
 * Set value of IBV_WC_RECV so consumers can test if a completion is a
 * receive by testing (opcode & IBV_WC_RECV).
 */
//128
    IBV_WC_RECV			= 1 << 7,
//    129
    IBV_WC_RECV_RDMA_WITH_IMM,

    IBV_WC_TM_ADD,
    IBV_WC_TM_DEL,
    IBV_WC_TM_SYNC,
    IBV_WC_TM_RECV,
    IBV_WC_TM_NO_TAG,
//    135
    IBV_WC_DRIVER1,
};

int main()
{
    printf("IBV_WC_SEND: %zu\n", IBV_WC_SEND);
    printf("IBV_WC_RDMA_WRITE: %zu\n", IBV_WC_RDMA_WRITE);
    printf("IBV_WC_RECV: %zu\n", IBV_WC_RECV);
    printf("IBV_WC_RECV_RDMA_WITH_IMM: %zu\n", IBV_WC_RECV_RDMA_WITH_IMM);
    printf("IBV_WC_DRIVER1: %zu\n", IBV_WC_DRIVER1);
}