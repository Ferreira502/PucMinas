// ------------------------- 
// Guia_1402.v
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

// Registrador de deslocamento a esquerda (6 bits)
// com carga inicial em TODOS os presets (LD)

module shift_left_6bit_loadall (
    input clk,         
    input clear,       
    input ld,          
    output [5:0] q     
);

reg [5:0] q_reg;

always @(posedge clk or posedge clear or posedge ld)
begin
    if (clear)
        q_reg <= 6'b000000;       
    else if (ld)
        q_reg <= 6'b111111;       
    else
        q_reg <= q_reg << 1;      
end

assign q = q_reg;

endmodule
