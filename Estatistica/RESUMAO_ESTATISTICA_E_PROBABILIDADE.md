# Resumão de Estatística e Probabilidade

Baseado na apostila **Estatística e Probabilidade - 2º 2026** e organizado conforme as matérias das pastas `Aulas`.

## Aula 01 - Introdução à Estatística

Estatística é a área que ajuda a coletar, organizar, analisar e interpretar dados para tomar decisões em situações com variabilidade.

Conceitos principais:

- **População ou universo (N):** conjunto completo de indivíduos, medidas ou valores que interessam ao estudo.
- **Amostra (n):** parte da população usada para tirar conclusões sobre o todo.
- **Inferência:** processo de usar uma amostra para estimar ou concluir algo sobre a população.
- **Etapas de um estudo estatístico:** levantar hipóteses, planejar, coletar dados, analisar informações e tomar decisões.

Classificação das variáveis:

- **Qualitativas nominais:** categorias sem ordem. Ex.: curso, cor, tipo de produto.
- **Qualitativas ordinais:** categorias com ordem. Ex.: nível de satisfação, escolaridade.
- **Quantitativas discretas:** contagens, geralmente números inteiros. Ex.: número de alunos aprovados.
- **Quantitativas contínuas:** medições em intervalos reais. Ex.: peso, tempo, espessura.

## Aula 02 - Estatística Descritiva: Dados Qualitativos

A estatística descritiva organiza e resume dados para facilitar a leitura do conjunto.

Para dados qualitativos, costuma-se usar:

- **Tabela de frequências:** mostra quantas vezes cada categoria aparece.
- **Frequência absoluta:** quantidade observada em cada categoria.
- **Frequência relativa:** proporção ou porcentagem de cada categoria.
- **Gráficos:** barras, setores/pizza e outros gráficos de categorias.

Ideia central: em variáveis qualitativas, o foco não é calcular média, mas comparar categorias e proporções.

## Aula 03 - Medidas de Tendência Central e Variabilidade

Medidas de tendência central resumem os dados em um valor típico.

- **Média aritmética:** soma dos valores dividida pelo número de observações.
  - Fórmula: `x̄ = Σxi / n`
  - É sensível a valores extremos.
- **Mediana (Md):** valor central dos dados ordenados.
  - Se `n` é ímpar: posição `(n + 1) / 2`.
  - Se `n` é par: média dos valores nas posições `n / 2` e `(n + 2) / 2`.
  - É mais resistente a valores extremos.
- **Moda (Mo):** valor que aparece com maior frequência.
- **Ponto médio:** centro entre mínimo e máximo.
  - Fórmula: `Pm = (Xmáx + Xmín) / 2`.

Medidas de variabilidade mostram o quanto os dados se espalham.

- **Amplitude:** diferença entre maior e menor valor.
  - Fórmula: `a = máximo - mínimo`.
- **Variância amostral:** média dos desvios quadráticos em relação à média, com `n - 1` no denominador.
  - Fórmula: `s² = Σ(xi - x̄)² / (n - 1)`.
- **Desvio-padrão:** raiz quadrada da variância, na mesma unidade dos dados.
  - Fórmula: `s = √[Σ(xi - x̄)² / (n - 1)]`.
- **Coeficiente de variação:** compara dispersão relativa entre conjuntos.
  - Fórmula: `CV = (s / x̄) × 100`.

## Aula 04 - Tabela de Frequência, Histograma, Medidas e Boxplot

Quando há muitos valores quantitativos, os dados podem ser agrupados em classes.

Passos para tabela de frequência:

- Definir o número de classes `k`, frequentemente `k ≈ √n`.
- Identificar mínimo e máximo.
- Calcular amplitude total: `a = máximo - mínimo`.
- Calcular amplitude da classe: `h = a / k`.
- Montar classes com limites, geralmente fechadas à esquerda e abertas à direita.
- Calcular `ni`, `fi`, `Ni` e `Fi`.

Frequências:

- `ni`: frequência absoluta da classe.
- `fi`: frequência relativa da classe.
- `Ni`: frequência absoluta acumulada.
- `Fi`: frequência relativa acumulada.

Gráficos:

- **Histograma:** barras encostadas para variáveis quantitativas agrupadas em classes.
- **Diagrama de pontos:** mostra concentração, mínimo, máximo e formato da distribuição.
- **Ramo-e-folhas:** parecido com histograma, mas preserva os valores originais.
- **Boxplot:** usa mínimo, `Q1`, mediana, `Q3` e máximo para resumir a distribuição.

Boxplot e outliers:

- `AIQ = Q3 - Q1`.
- Limite inferior: `Q1 - 1,5 × AIQ`.
- Limite superior: `Q3 + 1,5 × AIQ`.
- Valores fora desses limites são outliers.

## Aula 05 - Probabilidade: Introdução

Probabilidade mede a chance de eventos ocorrerem em experimentos aleatórios.

Conceitos:

- **Experimento aleatório:** resultado não é conhecido antes, mas os resultados possíveis são conhecidos.
- **Espaço amostral (E):** conjunto de todos os resultados possíveis.
- **Evento:** subconjunto do espaço amostral.
- **Evento complementar:** resultados que não pertencem ao evento `A`, indicado por `A̅`.

Definição clássica:

- Fórmula: `P(A) = número de casos favoráveis / número de casos possíveis`.
- Usada quando os resultados são equiprováveis.

Propriedades:

- `0 ≤ P(A) ≤ 1`.
- `P(E) = 1`.
- `P(A̅) = 1 - P(A)`.
- Evento impossível tem probabilidade `0`.

## Aula 06 - Probabilidade: Regra da Adição

A regra da adição é usada para calcular a probabilidade de ocorrer `A` ou `B`.

Eventos:

- **União:** `A ∪ B`, ocorre quando `A`, `B` ou ambos ocorrem.
- **Interseção:** `A ∩ B`, ocorre quando `A` e `B` ocorrem ao mesmo tempo.
- **Mutuamente excludentes:** não podem ocorrer juntos, então `A ∩ B = ∅`.

Fórmulas:

- Eventos quaisquer: `P(A ∪ B) = P(A) + P(B) - P(A ∩ B)`.
- Eventos mutuamente excludentes: `P(A ∪ B) = P(A) + P(B)`.

Pegadinha comum: se os eventos podem ocorrer juntos, precisa subtrair a interseção para não contar duas vezes.

## Aula 07 - Probabilidade: Regra da Multiplicação e Teorema de Bayes

### Regra da Multiplicação

É usada para calcular a probabilidade de `A` e `B` ocorrerem.

Probabilidade condicional:

- Fórmula: `P(A|B) = P(A ∩ B) / P(B)`, com `P(B) > 0`.
- Lê-se: probabilidade de `A` dado que `B` ocorreu.

Regra da multiplicação:

- Fórmula geral: `P(A ∩ B) = P(A|B) × P(B)`.
- Também pode ser escrita como: `P(A ∩ B) = P(B|A) × P(A)`.

Independência:

- `A` e `B` são independentes se a ocorrência de um não altera a chance do outro.
- Fórmula: `P(A ∩ B) = P(A) × P(B)`.

### Teorema de Bayes

Bayes atualiza probabilidades quando uma nova informação aparece.

Regra da probabilidade total:

- `P(B) = Σ P(Ai) × P(B|Ai)`.

Teorema de Bayes:

- `P(Ai|B) = [P(Ai) × P(B|Ai)] / [P(A1)P(B|A1) + ... + P(An)P(B|An)]`.

Interpretação:

- `P(Ai)` é probabilidade inicial, ou a priori.
- `P(Ai|B)` é probabilidade atualizada, ou a posteriori.

## Aula 08 - Variáveis Aleatórias Discretas e Binomial

Variável aleatória associa resultados de um experimento a valores numéricos.

Variável aleatória discreta:

- Assume valores contáveis, geralmente inteiros.
- Ex.: número de caras em lançamentos de moedas, número de defeitos, número de sucessos.

Função de probabilidade:

- `p(x) = P(X = x)`.
- Deve satisfazer `0 ≤ p(x) ≤ 1` e `Σp(x) = 1`.

Função acumulada:

- `F(x) = P(X ≤ x)`.

Distribuição Binomial:

- Usada quando há `n` repetições independentes, cada uma com sucesso ou fracasso.
- A probabilidade de sucesso `p` é constante.
- Notação: `X ~ Bin(n, p)`.
- Fórmula: `P(X = x) = C(n, x) p^x (1 - p)^(n - x)`.
- Combinação: `C(n, x) = n! / [x!(n - x)!]`.
- Média: `E(X) = np`.
- Variância: `Var(X) = np(1 - p)`.

Quando usar: número de sucessos em quantidade fixa de tentativas independentes.

## Aula 09 - Distribuição Hipergeométrica

A distribuição hipergeométrica conta sucessos em uma amostra retirada sem reposição.

Características:

- População finita de tamanho `N`.
- Existem `r` elementos com a característica de interesse.
- Amostra de tamanho `n`.
- As retiradas não são independentes, pois não há reposição.

Notação:

- `X ~ Hip(N, r, n)`.

Fórmula:

- `P(X = x) = [C(r, x) C(N - r, n - x)] / C(N, n)`.

Média e variância:

- `E(X) = np`, com `p = r / N`.
- `Var(X) = np(1 - p) × [(N - n) / (N - 1)]`.

Quando usar: sorteio sem reposição, inspeção de lotes, escolha de peças de uma caixa.

## Aula 10 - Distribuição de Poisson

A distribuição de Poisson modela número de ocorrências em um intervalo contínuo.

Características:

- Conta eventos discretos em tempo, área, volume, distância etc.
- A taxa média de ocorrência é constante.
- Ocorrências em intervalos diferentes são independentes.

Notação:

- `X ~ Po(λ)`.

Fórmula:

- `P(X = x) = e^(-λ) λ^x / x!`, para `x = 0, 1, 2, ...`.

Média e variância:

- `E(X) = λ`.
- `Var(X) = λ`.

Quando usar: chamadas por dia, clientes por hora, defeitos por metro quadrado, falhas por período.

## Aula 11 - Variáveis Aleatórias Contínuas, Exponencial e Normal

### Variáveis Aleatórias Contínuas

Assumem valores em intervalos reais. Em variáveis contínuas, a probabilidade de um valor exato é zero; calcula-se probabilidade em intervalos.

Função densidade:

- `f(x) ≥ 0`.
- Área total sob a curva: `∫ f(x) dx = 1`.
- Probabilidade em intervalo: `P(a ≤ X ≤ b) = ∫a^b f(x) dx`.

### Distribuição Exponencial

Relaciona-se com a Poisson, mas mede o tempo ou distância até o próximo evento.

Características:

- Taxa média constante `λ`.
- Eventos independentes.
- Notação: `X ~ Exp(λ)`.

Fórmulas:

- Densidade: `f(x) = λe^(-λx)`, para `x ≥ 0`.
- Média: `E(X) = 1 / λ`.
- Variância: `Var(X) = 1 / λ²`.

Quando usar: tempo até uma falha, tempo até chegada de cliente, distância até ocorrência.

### Distribuição Normal

É uma das distribuições mais importantes da estatística, base da inferência.

Características:

- Curva em forma de sino.
- Simétrica em torno da média `μ`.
- Área total sob a curva igual a 1.
- Média, mediana e moda coincidem em `μ`.

Notação:

- `X ~ N(μ, σ)`.

Padronização:

- `Z = (X - μ) / σ`.
- Após padronizar, `Z ~ N(0, 1)`.

Quando usar: fenômenos aproximadamente simétricos, medidas físicas, erros de medição e aproximações em inferência.

## Aula 12 - Inferência Estatística: Média com σ Conhecido

Inferência estatística usa dados de uma amostra para estimar características da população.

Conceitos:

- **Parâmetro:** medida populacional, como `μ`, `σ` ou `p`.
- **Estimador:** estatística amostral usada para estimar o parâmetro, como `x̄`, `s` ou `p̂`.
- **Estimativa pontual:** um único valor para estimar o parâmetro.
- **Intervalo de confiança:** faixa provável para o parâmetro.
- **Margem de erro:** parte somada e subtraída da estimativa.

Intervalo de confiança para média com `σ` conhecido:

- Fórmula: `x̄ ± zα/2 × (σ / √n)`.

Quando usar:

- População aproximadamente normal ou amostra grande.
- Desvio-padrão populacional `σ` conhecido.

Interpretação correta: com 95% de confiança, o método usado tende a produzir intervalos que contêm a verdadeira média em 95% das amostras.

## Aula 13 - Inferência: Média com σ Desconhecido

Quando `σ` não é conhecido, usa-se o desvio-padrão amostral `s`.

Distribuição t de Student:

- Usada principalmente para amostras pequenas com `σ` desconhecido.
- Tem `n - 1` graus de liberdade.
- É parecida com a normal, mas mais espalhada.
- Conforme `n` aumenta, aproxima-se da normal.

Intervalo de confiança para média com `σ` desconhecido:

- Fórmula: `x̄ ± t(n-1; α/2) × (s / √n)`.

Para grandes amostras:

- Pode-se usar aproximação normal:
- `x̄ ± zα/2 × (s / √n)`.

Quando usar:

- Use `t` quando `σ` é desconhecido e a amostra é pequena.
- Use `z` com `s` como aproximação quando `n ≥ 30`.

## Aula 14 - Inferência: Proporção

A proporção populacional `p` é estimada pela proporção amostral `p̂`.

Estimador:

- `p̂ = x / n`, em que `x` é o número de sucessos.

Intervalo de confiança para proporção:

- Fórmula: `p̂ ± zα/2 × √[p̂(1 - p̂) / n]`.

Quando usar:

- Amostra grande.
- Situação com sucesso/fracasso.
- Ex.: proporção de eleitores favoráveis, peças defeituosas, famílias com TV a cabo.

Interpretação:

- O intervalo indica valores plausíveis para a proporção populacional.
- A margem de erro aumenta quando a confiança aumenta e diminui quando o tamanho da amostra aumenta.

## Aula 15 - Cálculo do Tamanho da Amostra

O tamanho da amostra depende da margem de erro desejada, do nível de confiança e da variabilidade.

Para estimar média `μ`:

- Fórmula: `n = (zα/2 × σ / E)²`.
- `E` é a margem de erro máxima admitida.
- Se `σ` não for conhecido, pode-se usar uma estimativa anterior ou estudo piloto.

Para estimar proporção `p`:

- Fórmula: `n = p̂(1 - p̂) × (zα/2 / E)²`.
- Se não houver estimativa prévia de `p̂`, usa-se `p̂ = 0,5`, pois gera o maior tamanho de amostra.

Ideia central:

- Maior confiança exige maior amostra.
- Menor erro permitido exige maior amostra.
- Maior variabilidade exige maior amostra.

## Aula 16 - Teste de Hipóteses

Teste de hipóteses verifica se os dados amostrais trazem evidência suficiente contra uma afirmação sobre a população.

Elementos:

- **Hipótese nula (`H0`):** afirmação inicial, geralmente com igualdade.
- **Hipótese alternativa (`H1` ou `Ha`):** afirmação que se deseja investigar.
- **Nível de significância (`α`):** risco de rejeitar `H0` quando ela é verdadeira.
- **Estatística de teste:** valor calculado com base na amostra.
- **Região crítica:** valores que levam à rejeição de `H0`.
- **Valor-p:** probabilidade de observar resultado tão extremo quanto o obtido, assumindo `H0` verdadeira.

Erros:

- **Erro tipo I:** rejeitar `H0` sendo `H0` verdadeira.
- **Erro tipo II:** não rejeitar `H0` sendo `H0` falsa.

Decisão pelo valor-p:

- Se `valor-p < α`, rejeita-se `H0`.
- Se `valor-p ≥ α`, não se rejeita `H0`.

Tipos de teste:

- **Bilateral:** verifica diferença para mais ou para menos.
- **Unilateral à direita:** verifica se o parâmetro é maior.
- **Unilateral à esquerda:** verifica se o parâmetro é menor.

Estatísticas comuns:

- Média com `σ` conhecido: `Z = (x̄ - μ0) / (σ / √n)`.
- Média com `σ` desconhecido: `T = (x̄ - μ0) / (s / √n)`.
- Proporção: `Z = (p̂ - p0) / √[p0(1 - p0) / n]`.

## Aula 17 - Regressão: Correlação e Estimação da Reta

Correlação mede sentido e intensidade da relação linear entre duas variáveis.

Diagrama de dispersão:

- Coloca `X` em um eixo e `Y` no outro.
- Ajuda a visualizar se a relação parece positiva, negativa, forte, fraca ou inexistente.

Coeficiente de correlação de Pearson:

- Fórmula: `r = cov(X, Y) / (sx × sy)`.
- Intervalo: `-1 ≤ r ≤ 1`.

Interpretação:

- `r = 1`: relação linear positiva perfeita.
- `r = -1`: relação linear negativa perfeita.
- `r = 0`: ausência de associação linear.
- Quanto mais perto de `±1`, mais forte a relação linear.

Regressão linear simples:

- Modelo populacional: `Y = β0 + β1X`.
- Reta estimada: `ŷ = b0 + b1x`.

Interpretação:

- `b0`: intercepto, valor estimado de `Y` quando `X = 0`.
- `b1`: inclinação, variação média estimada em `Y` para aumento de uma unidade em `X`.

Quando usar:

- Quando existe relação aproximadamente linear e se deseja prever ou explicar `Y` a partir de `X`.

## Aula 18 - Regressão: Qualidade do Ajuste

Depois de estimar a reta, é preciso avaliar se ela explica bem os dados.

Coeficiente de determinação:

- Mede a proporção da variação de `Y` explicada pela regressão.
- Fórmula: `R² = VE / VT`.
- Em regressão linear simples: `R² = r² × 100`.

Interpretação:

- `R² = 80%` significa que 80% da variação observada em `Y` é explicada pela reta ajustada.
- Quanto maior o `R²`, melhor a reta explica os dados.
- `R²` alto não prova causalidade; apenas indica bom ajuste linear.

Cuidados:

- Verificar o diagrama de dispersão antes de confiar na reta.
- Não usar regressão linear quando a relação for claramente curva.
- Evitar previsões muito fora da faixa observada de `X`.
- Correlação e regressão não significam causa e efeito automaticamente.

## Guia rápido: quando usar cada distribuição

- **Binomial:** número de sucessos em `n` tentativas independentes, com `p` constante.
- **Hipergeométrica:** número de sucessos em amostra sem reposição.
- **Poisson:** número de ocorrências em intervalo de tempo, área, volume ou espaço.
- **Exponencial:** tempo ou distância até a próxima ocorrência.
- **Normal:** dados contínuos aproximadamente simétricos ou aproximações inferenciais.
- **t de Student:** inferência sobre média com `σ` desconhecido, especialmente amostras pequenas.

## Fórmulas mais importantes

- Média: `x̄ = Σxi / n`.
- Variância amostral: `s² = Σ(xi - x̄)² / (n - 1)`.
- Desvio-padrão: `s = √s²`.
- Coeficiente de variação: `CV = (s / x̄) × 100`.
- Probabilidade complementar: `P(A̅) = 1 - P(A)`.
- Adição: `P(A ∪ B) = P(A) + P(B) - P(A ∩ B)`.
- Condicional: `P(A|B) = P(A ∩ B) / P(B)`.
- Multiplicação: `P(A ∩ B) = P(A|B)P(B)`.
- Binomial: `P(X = x) = C(n, x)p^x(1 - p)^(n - x)`.
- Poisson: `P(X = x) = e^(-λ)λ^x / x!`.
- Hipergeométrica: `P(X = x) = [C(r, x)C(N-r, n-x)] / C(N, n)`.
- Normal padrão: `Z = (X - μ) / σ`.
- IC da média com `σ` conhecido: `x̄ ± zα/2(σ / √n)`.
- IC da média com `σ` desconhecido: `x̄ ± t(n-1; α/2)(s / √n)`.
- IC da proporção: `p̂ ± zα/2√[p̂(1 - p̂) / n]`.
- Tamanho amostral para média: `n = (zα/2σ / E)²`.
- Tamanho amostral para proporção: `n = p̂(1 - p̂)(zα/2 / E)²`.
- Correlação: `r = cov(X,Y) / (sxsy)`.
- Regressão: `ŷ = b0 + b1x`.
- Determinação: `R² = r² × 100`.

## Como estudar por prioridade

1. Dominar conceitos básicos: população, amostra, variável, evento e probabilidade.
2. Treinar estatística descritiva: média, mediana, moda, variância, desvio-padrão e boxplot.
3. Decorar regras de probabilidade: complemento, união, interseção, condicional e Bayes.
4. Saber escolher a distribuição correta: Binomial, Hipergeométrica, Poisson, Exponencial ou Normal.
5. Praticar intervalos de confiança e testes de hipóteses com atenção ao `σ` conhecido/desconhecido.
6. Entender correlação, regressão e interpretação de `R²`.

