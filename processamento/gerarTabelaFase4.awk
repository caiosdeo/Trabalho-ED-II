BEGIN{

  print "\\begin{table}[H]" >> "tabelaTratadosFase4.tex";
  print "\\caption{Média das Métricas de Desempenho}" >> "tabelaTratadosFase4.tex";
  print "\\label{tab:compressao}" >> "tabelaTratadosFase4.tex";
  print "\\begin{tabular}{c|c|c|c|c}" >> "tabelaTratadosFase4.tex";
  print "\\textbf{Algoritmo} &\\textbf{N} & \\textbf{Taxa de Compressão} & \\textbf{Armazenamento} & \\textbf{Tempo (ms)}\\\\" >> "tabelaTratadosFase4.tex";
  print "\\hline" >> "tabelaTratadosFase4.tex";

}

{
    print $1, "&", $2, "&", $3, "&", $4, "&", $5 "\\\\">> "tabelaTratadosFase4.tex";
}

END{

  print "\\end{tabular}" >> "tabelaTratadosFase4.tex";
  print "\\end{table}" >> "tabelaTratadosFase4.tex";
  
}
