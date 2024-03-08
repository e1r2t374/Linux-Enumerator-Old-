{ pkgs }: {
	deps = [
   pkgs.busybox
   pkgs.unixtools.ping
   pkgs.iputils
   pkgs.python38
   pkgs.netcat-gnu
		pkgs.wget
  pkgs.pacman
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}