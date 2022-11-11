# SmartDuster
Projeto de desenvolvimento de um aspirador de pó inteligente. Trabalho de conclusão do curso de Desenvolvimento android Devtitans.

#Parâmetros de retorno do .ino
>["RGS",SL, SU, SB, AA, AV, RE, REFT, RD, RDFT]
>Parâmetros comuns entre as chamadas
0x00 - se o sensor não identificar luminosidade.
0x01 ou mais - se o sensor identificar luminosidade.
0xFF - ocorreu erro na comunicação com o sensor, verificar a conexão e/ou o correto funcionamento do sensor.

OBS:
Para os parâmetros REFT e RDFT só existem 2 estados(00 e 01), devido a eles dependerem da ativação da roda.

>Parâmetros de retorno específicos
>>SL(sensor de luminosidade)
em RGS retorna
->0x00 se tiver sucesso
->0x01 se tiver falhado 
>>SU(sensor Ultrassônico)
em RGS retorna
->0x00 se tiver sucesso
->0x02 se tiver falhado 
>>SB(sensor de batida)
em RGS retorna
->0x00 se tiver sucesso
->0x03 se tiver falhado 
>>AA(ativador do aspirador)
em RGS retorna
->0x00 se tiver sucesso
->0x04 se tiver falhado 
>>AV(ativador da vassoura)
em RGS retorna
->0x00 se tiver sucesso
->0x05 se tiver falhado 
>>RE(motor da Roda Esquerda)
em RGS retorna
->0x00 se tiver sucesso
->0x06 se tiver falhado 
>>RD(motor da Roda Direita)
em RGS retorna
->0x00 se tiver sucesso
->0x07 se tiver falhado 

>>REFT(Força de tração da roda esquerda)
>>RDFT(Força de tração da roda direita)
