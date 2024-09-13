{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gtkmm4
    gcc
    pkg-config
    ninja
    meson
  ];
}

