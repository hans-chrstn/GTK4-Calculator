{ pkgs ? import <nixpkgs> {} }:

pkgs.mkDerivation {
  pname = "gtk_app";
  version = "1.0";

  src = ./.;

  nativeBuildInputs = with pkgs; [ gtkmm3 cmake pkg-config make gnumake gcc];

  buildPhase = ''
    mkdir -p build
    cd build
    cmake ..
    make
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp build/gtk_app $out/bin/
  '';
}

