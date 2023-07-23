#!/bin/bash


function buildCWWK_i3-N305Image {

		if [ ! -f 3rdparty/blobs/mainboard/CWWK/i3-N305/me.bin ]; then

		"Missing Proper Blob files"
		exit 1

	fi

	version='v1.1.0'

	docker run --rm -t -u $UID -v $PWD:/home/coreboot/coreboot \
		-v $HOME/.ssh:/home/coreboot/.ssh \
		-w /home/coreboot/coreboot coreboot/coreboot-sdk:2021-09-23_b0d87f753c \
		/bin/bash -c "make distclean"

	cp configs/config.CWWK_i3-N305 .config

	echo "Building coreboot for CWWK i3-N305"

	docker run --rm -t -u $UID -v $PWD:/home/coreboot/coreboot \
		-v $HOME/.ssh:/home/coreboot/.ssh \
		-w /home/coreboot/coreboot coreboot/coreboot-sdk:2021-09-23_b0d87f753c \
		/bin/bash -c "make olddefconfig && make"

	cp build/coreboot.rom CWWK_i3-N305_$version.rom
	if [ $? -eq 0 ]; then
		echo "Result binary placed in $PWD/CWWK_i3-N305_$version.rom" 
		sha256sum CWWK_i3-N305_$version.rom > CWWK_i3-N305_$version.rom.sha256
	else
		echo "Build failed!"
		exit 1
	fi
}



buildCWWK_i3-N305Image "CWWK_i3-N305"

