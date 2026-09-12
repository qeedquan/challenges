/*

Presumably everybody here knows that for the legacy BIOS, the tiniest bootable disk image is 512 bytes (the lower bound is due to the 2-byte magic at offset 510), and there is a bootsector demoscene where people try to fit the entire demo into the 510 bytes of usable space.

Now that the BIOS is being superseded by UEFI, there is a question: what will be the equivalent of a "bootsector demo" in the UEFI world?

More formally, here is what I'm curious about: what's the minimum size of a whole-drive image that boots on at least one UEFI?

Rules:

The answer must be a disk image, or must compile to a disk image.
The disk image should boot on at least one UEFI with CSM/Legacy boot disabled.
By "booting" I consider that the CPU starts executing instructions that have been loaded from the disk image. It does not matter what the image actually does.
Exploiting bugs in specific UEFI implementations is OK, unless the bug causes the firmware to attempt a legacy boot.
The winner is the image that is the smallest when encoded in the raw format. If there are multiple answers with the same image size, the one where the most space can be used for x86 code wins.

*/

#include <efi.h>
#include <efilib.h>

EFI_STATUS EFIAPI
efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	InitializeLib(ImageHandle, SystemTable);
	Print(L"Hello, World!\n");
	for (;;)
		;
	return EFI_SUCCESS;
}
