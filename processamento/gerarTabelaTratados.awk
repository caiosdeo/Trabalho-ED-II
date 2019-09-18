BEGIN{

  print "\\begin{table}[htbp]" >> "tabelaTratados.tex";
  print "\\caption{Média das Métricas de Desempenho}" >> "tabelaTratados.tex";
  print "\\label{tab:table1}" >> "tabelaTratados.tex";
  print "\\begin{tabular}{c|c|c|c|c}" >> "tabelaTratados.tex";
  print "\\textbf{Estrutura} & \\textbf{N} & \\textbf{Comparação} & \\textbf{Acessos} & \\textbf{Tempo (ms)}\\\\" >> "tabelaTratados.tex";
  print "\\hline" >> "tabelaTratados.tex";

}

{
    print $1, "&", $2, "&", $3, "&", $4, "&", $5 "\\\\">> "tabelaTratados.tex";
}

END{

  print "\\end{tabular}" >> "tabelaTratados.tex";
  print "\\end{table}" >> "tabelaTratados.tex";
  
}
