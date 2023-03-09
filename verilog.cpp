module mealy_11101(
input clk,
input rst,
input x,
output reg detected
);
parameter S0=3'b000, S1=3'b001, S2=3'b010, S3=3'b011, S4=3'b100;
// present_state & next-state logic
reg [2:0] present_state, next_state;
always @(posedge clk)
begin
if(rst)
present_state <= S0;
else
present_state <= next_state;
end
//state transition logic
always @(present_state, x)
case (present_state)
S0: if (x) next_state = S1; else next_state = S0;
S1: if (x) next_state = S2; else next_state = S0;
S2: if (x) next_state = S3; else next_state = S0;
S3: if (x) next_state = S3; else next_state = S4;
S4: if (x) next_state = S1; else next_state = S0;
default: next_state = S0;
endcase
// output logic
always @(present_state,x)
begin
case(present_state)
S4: if (x) detected = 1'b1; else detected = 1'b0 ;
default: detected = 1'b0;
endcase
end
endmodule
