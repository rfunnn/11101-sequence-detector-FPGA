module tb_mealy_11101;
reg clk=0;
always #5 clk = ~clk; // Create clock with period=10
// A testbench
reg rst = 1;
reg x = 0;
wire detected;
initial begin
#10 rst = 0;
#10 x = 1;
#10 x = 1;
#10 x = 1;
#10 x = 1;
#10 x = 0;
#10 x = 1;
#10 x = 0;
#10 x = 1;
#10 x = 0;
#10 x = 1;
#10 x = 1;
#10 x = 1;
#10 x = 0;
#10 x = 1;
#10 $finish; // Quit the simulation
end
mealy_11101 dut( .clk(clk), .rst(rst), .x(x), .detected(detected) );
endmodule
