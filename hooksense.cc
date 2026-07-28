-- [ESP Tab Components - Integrated UELinoriaLib Drawing ESP]
local DrawingFonts = {
    ["UI"] = 0,
    ["System"] = 1,
    ["Plex"] = 2,
    ["Monospace"] = 3
}
local DrawingFontNames = {"UI", "System", "Plex", "Monospace"}

-- Force refresh ESP on camera movement
local LastCameraCFrame = workspace.CurrentCamera.CFrame

local function GetColor(optionName, defaultColor)
    local fallback = defaultColor or Color3.fromRGB(255, 255, 255)
    if not Options then return fallback end
    local opt = Options[optionName]
    if not opt then return fallback end

    if typeof(opt) == "Color3" then
        return opt
    elseif typeof(opt) == "table" then
        if typeof(opt.Value) == "Color3" then
            return opt.Value
        elseif typeof(opt.Color) == "Color3" then
            return opt.Color
        elseif opt[1] and typeof(opt[1]) == "number" then
            return Color3.new(opt[1], opt[2], opt[3])
        end
    elseif typeof(opt) == "UserData" or typeof(opt) == "RBXScriptConnection" then
        if opt.Value and typeof(opt.Value) == "Color3" then
            return opt.Value
        end
    end
    return fallback
end

local function CreateLine(thickness, color)
    local line = Drawing.new("Line")
    line.Thickness = thickness or 1
    line.Color = color or Color3.fromRGB(0, 0, 0)
    line.Transparency = 1
    line.Visible = false
    return line
end

local function CreateText()
    local text = Drawing.new("Text")
    text.Size = 13
    text.Center = true
    text.Outline = true
    text.OutlineColor = Color3.fromRGB(0, 0, 0)
    text.Font = 2
    text.Visible = false
    return text
end

local function CreateSquare(filled)
    local sq = Drawing.new("Square")
    sq.Thickness = 1
    sq.Filled = (filled == true)
    sq.Transparency = 1
    sq.Visible = false
    return sq
end

local ESP_Drawing_Storage = {}
local function ImplementESPSetup(holder)
    pcall(function()
        holder.BoxFillFrame = Instance.new("Frame")
        holder.BoxFillFrame.Name = "BoxFill"
        holder.BoxFillFrame.AnchorPoint = Vector2.new(0, 0)
        holder.BoxFillFrame.BorderSizePixel = 0
        holder.BoxFillFrame.BackgroundTransparency = 1
        holder.BoxFillFrame.Visible = false
        holder.BoxFillFrame.Parent = BoxFillGui

        holder.BoxFillGradient = Instance.new("UIGradient")
        holder.BoxFillGradient.Parent = holder.BoxFillFrame
        holder.BoxFillRotationAngle = 0

        holder.BoxLines = {CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)}
        holder.BoxOutlines = {
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)
        }
        holder.CornerLines = {
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)
        }
        holder.CornerOutlines = {
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)
        }

        holder.HealthOutline = CreateSquare(true)
        holder.HealthBar = CreateSquare(true)
        holder.HealthText = CreateText()
        holder.Name = CreateText()
        holder.Distance = CreateText()
        holder.SmoothHealth = nil
        -- Force refresh flag
        holder.NeedsRefresh = true

        if holder.HealthOutline then holder.HealthOutline.Color = Color3.fromRGB(0, 0, 0) end
        if holder.HealthText then 
            holder.HealthText.Size = 11 
            holder.HealthText.Center = true 
        end
    end)
end

local function CreateDrawingESP(player)
    if player == LocalPlayer then return end
    if ESP_Drawing_Storage[player] then return end
    ESP_Drawing_Storage[player] = {}
    ImplementESPSetup(ESP_Drawing_Storage[player])
end

local function RemoveDrawingESP(player)
    if ESP_Drawing_Storage[player] then
        pcall(function()
            if ESP_Drawing_Storage[player].BoxFillFrame then
                ESP_Drawing_Storage[player].BoxFillFrame:Destroy()
            end
            for _, obj in pairs(ESP_Drawing_Storage[player]) do
                if type(obj) == "table" then
                    for _, subObj in pairs(obj) do
                        if subObj and subObj.Remove then subObj:Remove() end
                    end
                elseif type(obj) == "userdata" and obj.Remove then
                    obj:Remove()
                end
            end
        end)
        ESP_Drawing_Storage[player] = nil
    end
end

for _, p in ipairs(Players:GetPlayers()) do CreateDrawingESP(p) end
Players.PlayerAdded:Connect(CreateDrawingESP)
Players.PlayerRemoving:Connect(RemoveDrawingESP)

local function SetVisibilityFalse(esp)
    pcall(function()
        if esp.BoxFillFrame then esp.BoxFillFrame.Visible = false end
        if esp.BoxLines then for i = 1, 4 do esp.BoxLines[i].Visible = false end end
        if esp.BoxOutlines then for i = 1, 8 do esp.BoxOutlines[i].Visible = false end end
        if esp.CornerLines then for i = 1, 8 do esp.CornerLines[i].Visible = false end end
        if esp.CornerOutlines then for i = 1, 16 do esp.CornerOutlines[i].Visible = false end end
        if esp.HealthBar then esp.HealthBar.Visible = false end
        if esp.HealthOutline then esp.HealthOutline.Visible = false end
        if esp.HealthText then esp.HealthText.Visible = false end
        if esp.Name then esp.Name.Visible = false end
        if esp.Distance then esp.Distance.Visible = false end
        esp.NeedsRefresh = true
    end)
end

RunService.RenderStepped:Connect(function()
    pcall(function()
        local Camera = workspace.CurrentCamera
        if not Camera then return end

        -- Force refresh on camera movement
        local currentCFrame = Camera.CFrame
        if currentCFrame ~= LastCameraCFrame then
            LastCameraCFrame = currentCFrame
            for _, esp in pairs(ESP_Drawing_Storage) do
                esp.NeedsRefresh = true
            end
        end

        local espMaster = Toggles.EspMaster and Toggles.EspMaster.Value
        if not espMaster then
            for _, esp in pairs(ESP_Drawing_Storage) do SetVisibilityFalse(esp) end
            return
        end

        local boxColor = GetColor("BoxColor", Color3.fromRGB(255, 255, 255))
        local cornerColor = GetColor("CornerColor", Color3.fromRGB(0, 210, 255))
        local nameColor = GetColor("NameColor", Color3.fromRGB(255, 255, 255))
        local distColor = GetColor("DistColor", Color3.fromRGB(255, 255, 255))
        local hpTextColor = GetColor("HPTextColor", Color3.fromRGB(255, 255, 255))
        local nameStyle = Options.NameStyleDropdown and Options.NameStyleDropdown.Value or "Username"
        
        local selectedFontName = Options.EspFontDropdown and Options.EspFontDropdown.Value or "Plex"
        local currentDrawingFont = DrawingFonts[selectedFontName] or 2

        local hpFullColor = GetColor("HPFullColor", Color3.fromRGB(0, 255, 0))
        local hpHalfColor = GetColor("HPHalfColor", Color3.fromRGB(255, 170, 0))
        local hpLowColor = GetColor("HPLowColor", Color3.fromRGB(255, 0, 0))
        local lerpAlpha = Options.HealthLerpSlider and Options.HealthLerpSlider.Value or 0.2

        local boxFillEnabled = Toggles.EspBoxFill and Toggles.EspBoxFill.Value
        local boxFillTrans = Options.EspBoxFillTransparency and Options.EspBoxFillTransparency.Value or 0.5
        local fillCol1 = GetColor("EspBoxFillColor1", Color3.fromRGB(255, 0, 0))
        local fillCol2 = GetColor("EspBoxFillColor2", Color3.fromRGB(0, 255, 0))
        local fillCol3 = GetColor("EspBoxFillColor3", Color3.fromRGB(0, 0, 255))
        local fillRotateEnabled = Toggles.EspBoxFillRotate and Toggles.EspBoxFillRotate.Value
        local fillRotateSpeed = Options.EspBoxFillRotateSpeed and Options.EspBoxFillRotateSpeed.Value or 1

        for player, esp in pairs(ESP_Drawing_Storage) do
            pcall(function()
                local character = player.Character
                local rootPart = character and character:FindFirstChild("HumanoidRootPart")
                local humanoid = character and character:FindFirstChildOfClass("Humanoid")

                if character and rootPart and humanoid and humanoid.Health > 0 then
                    if TeamCheckEnabled and player.Team == LocalPlayer.Team then
                        esp.SmoothHealth = nil
                        SetVisibilityFalse(esp)
                        return
                    end

                    local rootPos, onScreen = Camera:WorldToViewportPoint(rootPart.Position)
                    
                    if onScreen and rootPos.Z > 0 then
                        local headOffset = rootPart.CFrame * CFrame.new(0, 2.5, 0)
                        local feetOffset = rootPart.CFrame * CFrame.new(0, -3.0, 0)
                        
                        local headPos = Camera:WorldToViewportPoint(headOffset.Position)
                        local feetPos = Camera:WorldToViewportPoint(feetOffset.Position)
                        
                        local height = math.abs(headPos.Y - feetPos.Y)
                        local width = height * 0.48
                        local boxX = math.round(rootPos.X - (width / 2))
                        local boxY = math.round(headPos.Y)
                        
                        local selectedName = (nameStyle == "Display Name") and player.DisplayName or player.Name
                        local maxHp = (humanoid.MaxHealth > 0) and humanoid.MaxHealth or 100
                        local targetHp = math.clamp(humanoid.Health, 0, maxHp)
                        
                        if not esp.SmoothHealth then 
                            esp.SmoothHealth = targetHp 
                        else
                            esp.SmoothHealth = esp.SmoothHealth + (targetHp - esp.SmoothHealth) * lerpAlpha
                        end

                        local pct = math.clamp(esp.SmoothHealth / maxHp, 0, 1)
                        local mathWidth, mathHeight = math.round(width), math.round(height)

                        local textSize = math.clamp(math.round(mathHeight * 0.28), 9, 14)
                        local hpTextSize = math.clamp(math.round(mathHeight * 0.22), 8, 12)

                        if esp.Name then esp.Name.Font = currentDrawingFont; esp.Name.Size = textSize end
                        if esp.Distance then esp.Distance.Font = currentDrawingFont; esp.Distance.Size = textSize end
                        if esp.HealthText then esp.HealthText.Font = currentDrawingFont; esp.HealthText.Size = hpTextSize end

                        -- Box Fill Gradient
                        if boxFillEnabled and esp.BoxFillFrame then
                            esp.BoxFillFrame.Position = UDim2.new(0, boxX, 0, boxY)
                            esp.BoxFillFrame.Size = UDim2.new(0, mathWidth, 0, mathHeight)
                            esp.BoxFillFrame.BackgroundTransparency = boxFillTrans
                            
                            esp.BoxFillGradient.Color = ColorSequence.new({
                                ColorSequenceKeypoint.new(0, fillCol1),
                                ColorSequenceKeypoint.new(0.5, fillCol2),
                                ColorSequenceKeypoint.new(1, fillCol3)
                            })
                            
                            if fillRotateEnabled then
                                esp.BoxFillRotationAngle = (esp.BoxFillRotationAngle + (0.5 * fillRotateSpeed)) % 360
                            end
                            esp.BoxFillGradient.Rotation = esp.BoxFillRotationAngle
                            esp.BoxFillFrame.Visible = true
                        else
                            if esp.BoxFillFrame then esp.BoxFillFrame.Visible = false end
                        end

                        -- Corner Box
                        local corner = esp.CornerLines
                        local cornerOut = esp.CornerOutlines
                        local isCorner = Toggles.EspCornerBox and Toggles.EspCornerBox.Value
                        local isNormalBox = Toggles.EspBox and Toggles.EspBox.Value

                        if isCorner then
                            local cl = math.clamp(math.round(mathWidth * 0.22), 3, 12)
                            corner[1].From, corner[1].To = Vector2.new(boxX, boxY), Vector2.new(boxX + cl, boxY)
                            corner[2].From, corner[2].To = Vector2.new(boxX, boxY), Vector2.new(boxX, boxY + cl)
                            corner[3].From, corner[3].To = Vector2.new(boxX + mathWidth, boxY), Vector2.new(boxX + mathWidth - cl, boxY)
                            corner[4].From, corner[4].To = Vector2.new(boxX + mathWidth, boxY), Vector2.new(boxX + mathWidth, boxY + cl)
                            corner[5].From, corner[5].To = Vector2.new(boxX, boxY + mathHeight), Vector2.new(boxX + cl, boxY + mathHeight)
                            corner[6].From, corner[6].To = Vector2.new(boxX, boxY + mathHeight), Vector2.new(boxX, boxY + mathHeight - cl)
                            corner[7].From, corner[7].To = Vector2.new(boxX + mathWidth, boxY + mathHeight), Vector2.new(boxX + mathWidth - cl, boxY + mathHeight)
                            corner[8].From, corner[8].To = Vector2.new(boxX + mathWidth, boxY + mathHeight), Vector2.new(boxX + mathWidth, boxY + mathHeight - cl)

                            cornerOut[1].From, cornerOut[1].To = Vector2.new(boxX - 1, boxY - 1), Vector2.new(boxX + cl + 1, boxY - 1)
                            cornerOut[2].From, cornerOut[2].To = Vector2.new(boxX - 1, boxY - 1), Vector2.new(boxX - 1, boxY + cl + 1)
                            cornerOut[3].From, cornerOut[3].To = Vector2.new(boxX + mathWidth + 1, boxY - 1), Vector2.new(boxX + mathWidth - cl - 1, boxY - 1)
                            cornerOut[4].From, cornerOut[4].To = Vector2.new(boxX + mathWidth + 1, boxY - 1), Vector2.new(boxX + mathWidth + 1, boxY + cl + 1)
                            cornerOut[5].From, cornerOut[5].To = Vector2.new(boxX - 1, boxY + mathHeight + 1), Vector2.new(boxX + cl + 1, boxY + mathHeight + 1)
                            cornerOut[6].From, cornerOut[6].To = Vector2.new(boxX - 1, boxY + mathHeight + 1), Vector2.new(boxX - 1, boxY + mathHeight - cl - 1)
                            cornerOut[7].From, cornerOut[7].To = Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1), Vector2.new(boxX + mathWidth - cl - 1, boxY + mathHeight + 1)
                            cornerOut[8].From, cornerOut[8].To = Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1), Vector2.new(boxX + mathWidth + 1, boxY + mathHeight - cl - 1)
                            cornerOut[9].From, cornerOut[9].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + cl - 1, boxY + 1)
                            cornerOut[10].From, cornerOut[10].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + 1, boxY + cl - 1)
                            cornerOut[11].From, cornerOut[11].To = Vector2.new(boxX + mathWidth - 1, boxY + 1), Vector2.new(boxX + mathWidth - cl + 1, boxY + 1)
                            cornerOut[12].From, cornerOut[12].To = Vector2.new(boxX + mathWidth - 1, boxY + 1), Vector2.new(boxX + mathWidth - 1, boxY + cl - 1)
                            cornerOut[13].From, cornerOut[13].To = Vector2.new(boxX + 1, boxY + mathHeight - 1), Vector2.new(boxX + cl - 1, boxY + mathHeight - 1)
                            cornerOut[14].From, cornerOut[14].To = Vector2.new(boxX + 1, boxY + mathHeight - 1), Vector2.new(boxX + 1, boxY + mathHeight - cl + 1)
                            cornerOut[15].From, cornerOut[15].To = Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1), Vector2.new(boxX + mathWidth - cl + 1, boxY + mathHeight - 1)
                            cornerOut[16].From, cornerOut[16].To = Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1), Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - cl + 1)

                            for i = 1, 8 do corner[i].Color = cornerColor; corner[i].Visible = true end
                            for i = 1, 16 do cornerOut[i].Color = Color3.fromRGB(0, 0, 0); cornerOut[i].Visible = true end
                        else
                            for i = 1, 8 do corner[i].Visible = false end
                            for i = 1, 16 do cornerOut[i].Visible = false end
                        end

                        -- Normal Box
                        local lines = esp.BoxLines
                        local outs = esp.BoxOutlines
                        if isNormalBox and not isCorner then
                            lines[1].From, lines[1].To = Vector2.new(boxX, boxY), Vector2.new(boxX + mathWidth, boxY)
                            lines[2].From, lines[2].To = Vector2.new(boxX + mathWidth, boxY), Vector2.new(boxX + mathWidth, boxY + mathHeight)
                            lines[3].From, lines[3].To = Vector2.new(boxX + mathWidth, boxY + mathHeight), Vector2.new(boxX, boxY + mathHeight)
                            lines[4].From, lines[4].To = Vector2.new(boxX, boxY + mathHeight), Vector2.new(boxX, boxY)
                            for i = 1, 4 do lines[i].Color = boxColor; lines[i].Visible = true end

                            outs[1].From, outs[1].To = Vector2.new(boxX - 1, boxY - 1), Vector2.new(boxX + mathWidth + 1, boxY - 1)
                            outs[2].From, outs[2].To = Vector2.new(boxX + mathWidth + 1, boxY - 1), Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1)
                            outs[3].From, outs[3].To = Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1), Vector2.new(boxX - 1, boxY + mathHeight + 1)
                            outs[4].From, outs[4].To = Vector2.new(boxX - 1, boxY + mathHeight + 1), Vector2.new(boxX - 1, boxY - 1)
                            outs[5].From, outs[5].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + mathWidth - 1, boxY + 1)
                            outs[6].From, outs[6].To = Vector2.new(boxX + mathWidth - 1, boxY + 1), Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1)
                            outs[7].From, outs[7].To = Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1), Vector2.new(boxX + 1, boxY + mathHeight - 1)
                            outs[8].From, outs[8].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + 1, boxY + mathHeight - 1)
                            for i = 1, 8 do outs[i].Visible = true end
                        else
                            for i = 1, 4 do lines[i].Visible = false end
                            for i = 1, 8 do outs[i].Visible = false end
                        end

                        -- Healthbar
                        if Toggles.EspHealth and Toggles.EspHealth.Value then
                            local barWidth = 1.5
                            local outlinePadding = 1
                            local barX = boxX - 5
                            
                            esp.HealthOutline.Size = Vector2.new(barWidth + (outlinePadding * 2), mathHeight + (outlinePadding * 2))
                            esp.HealthOutline.Position = Vector2.new(barX - outlinePadding, boxY - outlinePadding)
                            esp.HealthOutline.Visible = true

                            local healthHeight = math.clamp(math.round(mathHeight * pct), 0, mathHeight)
                            local barY = boxY + (mathHeight - healthHeight)

                            if healthHeight > 0 then
                                esp.HealthBar.Size = Vector2.new(barWidth, healthHeight)
                                esp.HealthBar.Position = Vector2.new(barX, barY)

                                local finalCalculatedColor = hpFullColor
                                if pct > 0.5 then
                                    local alpha = math.clamp((pct - 0.5) * 2, 0, 1)
                                    finalCalculatedColor = hpHalfColor:Lerp(hpFullColor, alpha)
                                else
                                    local alpha = math.clamp(pct * 2, 0, 1)
                                    finalCalculatedColor = hpLowColor:Lerp(hpHalfColor, alpha)
                                end

                                esp.HealthBar.Color = finalCalculatedColor or Color3.fromRGB(0, 255, 0)
                                esp.HealthBar.Visible = true
                            else
                                esp.HealthBar.Visible = false
                            end

                            if Toggles.EspHealthText and Toggles.EspHealthText.Value then
                                esp.HealthText.Text = tostring(math.round(targetHp))
                                esp.HealthText.Position = Vector2.new(barX - (hpTextSize + 2), math.clamp(barY - 4, boxY - 4, boxY + mathHeight - 10))
                                esp.HealthText.Color = hpTextColor
                                esp.HealthText.Visible = true
                            else
                                esp.HealthText.Visible = false
                            end
                        else
                            esp.HealthOutline.Visible = false
                            esp.HealthBar.Visible = false
                            esp.HealthText.Visible = false
                        end

                        -- Name & Distance - Force update with refresh
                        if Toggles.EspName and Toggles.EspName.Value then
                            esp.Name.Text = selectedName
                            esp.Name.Position = Vector2.new(boxX + (mathWidth / 2), boxY - (textSize + 2))
                            esp.Name.Color = nameColor
                            esp.Name.Visible = true
                        else
                            esp.Name.Visible = false
                        end

                        if Toggles.EspDistance and Toggles.EspDistance.Value then
                            local dist = math.floor((Camera.CFrame.Position - rootPart.Position).Magnitude)
                            esp.Distance.Text = "[" .. tostring(dist) .. "m]"
                            esp.Distance.Position = Vector2.new(boxX + (mathWidth / 2), boxY + mathHeight + 2)
                            esp.Distance.Color = distColor
                            esp.Distance.Visible = true
                        else
                            esp.Distance.Visible = false
                        end
                        
                        esp.NeedsRefresh = false
                    else
                        esp.SmoothHealth = nil
                        SetVisibilityFalse(esp)
                    end
                else
                    esp.SmoothHealth = nil
                    SetVisibilityFalse(esp)
                end
            end)
        end
    end)
end)
