#!/usr/bin/env bash
/usr/src/kernels/$(uname -r)/scripts/sign-file \
	sha256 \
	/var/lib/dkms/mok.key \
	/var/lib/dkms/mok.pub \
	fake_device.ko
/usr/src/kernels/$(uname -r)/scripts/sign-file \
	sha256 \
	/var/lib/dkms/mok.key \
	/var/lib/dkms/mok.pub \
	fake_driver.ko

