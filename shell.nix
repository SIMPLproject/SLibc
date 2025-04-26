{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {

	packages = with pkgs; [
		llvm
		gnumake
		clang
		bear
		cloc
	];
}
