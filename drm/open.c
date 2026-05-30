#include <fcntl.h>
#include <sys/ioctl.h>
#include <drm/drm.h>
#include <stdio.h>

int main()
{
	int fd = open("/dev/dri/card0", O_RDWR);

	struct drm_version version;
	ioctl(fd, DRM_IOCTL_VERSION, &version);

	printf("Version: %d.%d.%d\n", version.version_major,
				      version.version_minor,
				      version.version_patchlevel);

	return 0;
}
