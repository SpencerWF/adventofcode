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
    local input = lines_from("../../input/2015/input3.txt")
    local cmd = 1
    local houses = {}
    houses["0:0"]=false
    local pos = {0,0}
    local human_pos = {0,0}
    local robo_pos = {0,0}
    local d = {}
    d["<"]={-1,0}
    d[">"]={1,0}
    d["^"]={0,1}
    d["v"]={0,-1}
    local count = 1

    for dir in input[1]:gmatch"." do
        if(cmd%2==1) then
            human_pos[1] = human_pos[1] + d[dir][1]
            human_pos[2] = human_pos[2] + d[dir][2]
            pos[1] = human_pos[1]
            pos[2] = human_pos[2]
            -- print("House ["..pos[1]..":"..pos[2].."] was visited, count is:"..count..", cmd is "..cmd)
            print(dir)
        else
            robo_pos[1] = robo_pos[1] + d[dir][1]
            robo_pos[2] = robo_pos[2] + d[dir][2]
            pos[1] = robo_pos[1]
            pos[2] = robo_pos[2]
        end

        if (houses[pos[1]..":"..pos[2]] == nil) then
            houses[pos[1]..":"..pos[2]] = true
            count = count + 1

        end

        cmd = cmd + 1
    end
    print("Number of houses with visits from Santa are:" .. count)
end

main()