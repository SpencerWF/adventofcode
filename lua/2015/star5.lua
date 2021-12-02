function file_exists(filename)
    local f = io.open(filename, "rb")
    if f then f:close() end
    return f ~= nil
end

function lines_from(filename)
    if not file_exists(filename) then return {} end
    lines = {}
    for line in io.lines(filename) do
        lines[#lines+1] = line
    end
    return lines
end

function main()
    local input = lines_from("../../input/2015/test.txt")
    local houses = {}
    local pos = {0,0}
    local d = {}
    d["<"]={-1,0}
    d[">"]={1,0}
    d["^"]={0,1}
    d["v"]={0,-1}
    local count = 1

    for dir in input[1]:gmatch"." do
        pos[1] = pos[1] + d[dir][1]
        pos[2] = pos[2] + d[dir][2]
        if(houses[pos[1]..":"..pos[2]] == false) then
            houses[pos[1]..":"..pos[2]] = true
            -- count = count + 1
            print("House ["..pos[1]..":"..pos[2].."] was visited a second time, count is:"..count)
        elseif (houses[pos[1]..":"..pos[2]] == nil) then
            houses[pos[1]..":"..pos[2]] = false
            count = count + 1
        end
    end
    print("Number of houses with multiple visits from Santa are:" .. count)
end

main()