# Verificador de Código de Barras

Trata-se de um trabalho apresentado para a disciplina de Algoritmos e Programação I, do Curso de Ciência da Computação, da Universidade do Vale do Itajaí (UNIVALI).

## 🚀 Equipe

Gabriel Joaquim Schlindwein Odisi (gabriel.8525404@edu.univali.br)
Guilherme Keller de Souza (guilherme.8535469@edu.univali.br)
Wagner Atoguia Lima Junior (wagatoguia@edu.univali.br)

---

## 📋 Descrição

Este programa em C++ verifica a validade de um código de barras EAN-13, calculando e conferindo o dígito verificador.  
Ele:

- Recebe um número de 13 dígitos (sem espaços);
- Calcula o dígito verificador conforme a regra EAN-13;
- Informa se o código de barras está correto ou não.

---

## 🎯 Funcionalidades

1. Validação do número de dígitos (exatamente 13 dígitos).  
2. Cálculo do dígito verificador:  
   - Soma alternada de dígitos (peso 1 e 3);  
   - Ajuste para o próximo múltiplo de 10;  
   - Comparação com o último dígito fornecido.  
3. Mensagens de erro para entradas fora do formato esperado.
