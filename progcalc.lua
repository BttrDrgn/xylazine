premake.modules.lua = {}
local m = premake.modules.lua
local p = premake

local function findAll(str, sub)
	local found = 0
	local positions = {}
	while(found)do
		found = found + 1
		found = str:find(sub, found)
		table.insert(positions, found)
	end
	return positions
end

function tablelength(T)
  local count = 0
  for _ in pairs(T) do count = count + 1 end
  return count
end

newaction {
    trigger = "progcalc",
    description = "Calculate progress of the reimplementation project by completed functions",

    onEnd = function()
		srcFiles = os.matchfiles("src/game/**.c*")
		headerFiles = os.matchfiles("src/game/**.h*")
		
		totalDone = 0
		totalThunks = 0
		totalTodo = 0
		
		for index, name in pairs(srcFiles) do
			totalDone = totalDone + tablelength(findAll(io.open(name, "r"):read("*all"), "//DONE : 0x"))
			totalThunks = totalThunks + tablelength(findAll(io.open(name, "r"):read("*all"), "//THUNK : 0x"))
			totalTodo = totalTodo + tablelength(findAll(io.open(name, "r"):read("*all"), "//TODO : 0x"))
		end

		for index, name in pairs(headerFiles) do
			totalDone = totalDone + tablelength(findAll(io.open(name, "r"):read("*all"), "//DONE : 0x"))
			totalThunks = totalThunks + tablelength(findAll(io.open(name, "r"):read("*all"), "//THUNK : 0x"))
			totalTodo = totalTodo + tablelength(findAll(io.open(name, "r"):read("*all"), "//TODO : 0x"))
		end
		
		totalFuncs = 15393
		
		donePercent = ((totalDone/totalFuncs)*100)
		thunkPercent = ((totalThunks/totalFuncs)*100)
		todoPercent = ((totalTodo/totalFuncs)*100)
		totalPercent = (((totalDone + totalThunks + totalTodo)/totalFuncs)*100)
		
		print("\n----- Progress Stats -----")
		print("-- Count:")
		print("Completed: " .. totalDone)
		print("Thunks: " .. totalThunks)
		print("Todo: " .. totalTodo)
		print("Total: " .. totalDone + totalThunks + totalTodo .. "/" .. totalFuncs)
		print("\n-- Percent:")
		print("Completed: " .. string.format("%.2f", donePercent) .. "%")
		print("Thunks: " .. string.format("%.2f", thunkPercent) .. "%")
		print("Todo: " .. string.format("%.2f", todoPercent) .. "%")
		print("Total: " .. string.format("%.2f", totalPercent) .. "%")
		print("--------------------------\n")
    end
}

return m