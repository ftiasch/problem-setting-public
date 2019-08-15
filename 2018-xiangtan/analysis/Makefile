../release/analysis.pdf: analysis.md
	mkdir -p ../release
	pandoc -t beamer -fmarkdown-implicit_figures --latex-engine=xelatex -V fontsize=15pt -V CJKmainfont='Source Han Sans CN' analysis.md -o../release/analysis.pdf
