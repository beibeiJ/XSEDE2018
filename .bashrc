# Source global definitions
if [ -f /etc/bashrc ]; then
        . /etc/bashrc
fi

module swap pgi pgi/18.1
module load mpi/pgi_openmpi

PATH=$PATH:./
