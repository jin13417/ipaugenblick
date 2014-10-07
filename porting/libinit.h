/*
 * libinit.h
 *
 *  Created on: Jul 6, 2014
 *      Author: Vadim Suraev vadim.suraev@gmail.com
 *  Contains function prototypes for initialization of
 *  Linux TCP/IP ported to userland and integrated with DPDK 1.6
 */

#ifndef __LIBINIT_H_
#define __LIBINIT_H_
/* This function returns a pointer to kernel's interface structure, required to access the driver
 * Parameter:ethernet port number
 */
void *get_dpdk_dev_by_port_num(int port_num);
/* This function allocates rte_mbuf */
void *get_buffer();
char *get_first_ip_from_config();
/* this function gets a pointer to data in the newly allocated rte_mbuf */
void *get_data_ptr(void *buf);
/* this function releases the rte_mbuf */
void release_buffer(void *buf);
/*
 * This function must be called prior any other in this package.
 * It initializes all the DPDK libs, reads the configuration, initializes the stack's
 * subsystems, allocates mbuf pools etc.
 * Parameters: refer to DPDK EAL parameters.
 * For example -c <core mask> -n <memory channels> -- -p <port mask>
 */
int dpdk_linux_tcpip_init(int argc,char **argv);
/* this function returns an available mbufs count */
int get_buffer_count();

#endif /* __LIBINIT_H_ */
