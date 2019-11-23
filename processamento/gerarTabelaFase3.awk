BEGIN{

  print "\\begin{table}[htbp]" >> "tabelaTratadosFase3.tex";
  print "\\caption{Média das Métricas de Desempenho}" >> "tabelaTratadosFase3.tex";
  print "\\label{tab:table1}" >> "tabelaTratadosFase3.tex";
  print "\\begin{tabular}{c|c|c|c|c|c}" >> "tabelaTratadosFase3.tex";
  print "\\textbf{Estrutura} & \\textbf{Modo} &\\textbf{N} & \\textbf{Comparação} & \\textbf{Acessos} & \\textbf{Tempo (ms)}\\\\" >> "tabelaTratadosFase3.tex";
  print "\\hline" >> "tabelaTratadosFase3.tex";

}

{
    print $1, "&", $2, "&", $3, "&", $4, "&", $5 ,"&", $6 "\\\\">> "tabelaTratadosFase3.tex";
}

END{

  print "\\end{tabular}" >> "tabelaTratadosFase3.tex";
  print "\\end{table}" >> "tabelaTratadosFase3.tex";
  
}
