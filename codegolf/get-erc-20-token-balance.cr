# Ethereum is a blockchain platform. It has its own native cryptocurrency, ether, but in this challenge, we'll be focusing on its ability to run smart contracts.
#
# The ERC-20 standard describes an implementation of fungible tokens within a smart contract. Some examples of this implementation are EOS, OmiseGo, and the Golem Network Token. In this challenge, your job is to find the amount of tokens owned by a certain address using the fewest bytes possible.
#
# The standard defines a balanceOf(address) contract method which is simple enough to use; however, it returns it in terms of a much smaller unit. To get the actual balance, you must divide the result by 10 to the power of whatever the decimals() method returns. For example, calling balanceOf(0x4530d03744d7ef769025623d31966da1e8485eef) returns 1.500000000000015e+21, and dividing it by 10^decimals() (10^18) results in the true balance of 1500.000000000015.
#
# Notes
# Assume that the computer that your program/function/etc. will be running on is running a fully-synced Geth node on the Ethereum mainnet with the JSON-RPC endpoint listening on the default port of localhost:8545.
# Your program should take two inputs: the token contract address (e.g. 0xea097a2b1db00627b2fa17460ad260c016016977) and the wallet address (e.g. 0x4530d03744d7ef769025623d31966da1e8485eef). Input can be taken in any reasonable format, such as a string, an integer, or an array of bytes (NB: Ethereum addresses are 20 bytes long).
# It should have one output: the token balance of the address in any reasonable format. Cases where the balance is zero must still be handled.
# Loss of fine floating-point precision in the final balance (e.g. the 17th or 18th decimal after dividing the balance by 10^decimals()) is okay.
# The ERC-20 standard technically says that the decimals() method might not be implemented; however, you may assume that it is.
# The use of libraries like web3.js is permitted, but discouraged.
# Standard loopholes are obviously not allowed.
# Test Cases
# token, wallet -> balance
# 0xea097a2b1db00627b2fa17460ad260c016016977, 0x4530d03744d7ef769025623d31966da1e8485eef -> 1500.000000000015
# 0xab95e915c123fded5bdfb6325e35ef5515f1ea69, 0x4530d03744d7ef769025623d31966da1e8485eef -> 317.18737335873794694
# 0x6810e776880c02933d47db1b9fc05908e5386b96, 0x3257bde8cf067ae6f1ddc0e4b140fe02e3c5e44f -> 8495410
# 0xb64ef51c888972c908cfacf59b47c1afbc0ab8ac, 0x0be3dead1ba261560362361838dd9671a34b63bb -> 314873.06011271
# Reference Implementation
# A reference implementation written in Crystal can be found here.
# https://gist.github.com/nickbclifford/56efe3ebee672db64471b987ab725747

require "big"
require "http/client"
require "json"

def send_contract_call(to address, data)
  JSON.parse(HTTP::Client.post("localhost:8545", body: {
    "jsonrpc" => "2.0",
    "method" => "eth_call",
    "params" => [{
      "to" => address,
      "data" => data
    }, "latest"],
    "id" => 1
  }.to_json).body)["result"]
end

BALANCE_METHOD_ID = "0x70a08231" # First 4 bytes of Keccak256("balanceOf(address)")
DECIMALS_METHOD_ID = "0x313ce567" # First 4 bytes of Keccak256("decimals()")

token = ARGV[0]
wallet = ARGV[1][2..-1] # Remove "0x" from beginning

balance = BigInt.new(send_contract_call(
  to: token,
  data: BALANCE_METHOD_ID + wallet.rjust(64, '0') # Pad wallet address to 32 bytes before appending
).as_s[2..-1], 16)

decimals = send_contract_call(
  to: token,
  data: DECIMALS_METHOD_ID
).as_s[2..-1].to_i(16)

puts BigDecimal.new(balance, decimals) # Really just `balance / (10 ** decimals)`
