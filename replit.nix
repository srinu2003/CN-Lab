{ pkgs }: {
	deps = [
   pkgs.vim
   pkgs.texinfoInteractive
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}