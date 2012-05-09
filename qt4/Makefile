.PHONY:  all
# Required SVG files
svgs := $(wildcard *.svg)

# Generated PNG (intermediate) files
genpng := $(patsubst %.svg,%.png,$(svgs))

all: filminasqt.pdf

filminasqt.pdf: filminasqt.txt slides.style ${genpng}
	rst2pdf filminasqt.txt -b1 -s slides.style -o $@
	

%.png: %.svg
	inkscape "$<" --export-png="$@"
	
	
clean:
	rm filminasqt.pdf
	
re: clean all