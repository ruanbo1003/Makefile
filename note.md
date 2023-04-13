
## syntax  
targets: prerequisites
    command1
    command2
    command3


## variables
* $@ : target file
* $^ : all prerequisites
* $< : the first prerequisite - the first thing after the `:`


## relate
* https://www.gnu.org/software/make/manual/make.html