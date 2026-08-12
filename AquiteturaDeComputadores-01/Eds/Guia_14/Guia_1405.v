// ------------------------- 
// Guia_1405.v
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

// Conversor Paralelo–Serie de 6 bits

module parallel_to_serial_6bit (
    input clk,           
    input clear,         
    input load,          
    input [5:0] data_in, 
    output reg data_out  
);

reg [5:0] shift_reg;

always @(posedge clk or posedge clear)
begin
    if (clear)
        shift_reg <= 6'b000000;
    else if (load)
        shift_reg <= data_in;         
    else
        shift_reg <= shift_reg >> 1;  
end

always @(*) begin
    data_out = shift_reg[0];
end

endmodule
