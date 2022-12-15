# so-projeto-1

Ordem dos locks: {Mutex} Tabela de Ficheiros Abertos (Free) -> {Mutex} Entrada da TFA (Indice Ascendente) -> {Mutex} Tabela de Inode (Free) ->  {RW Lock} INodes (Indice Ascendente) -> {Mutex} Block (Free)

TODO: Tirar os locks das structs dos INodes e das Entradas da Tabela.